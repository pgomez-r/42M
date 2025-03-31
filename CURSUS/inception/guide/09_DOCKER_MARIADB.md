# Creating a Mariadb container

## Step 1. Create the Dockerfile for MariaDB

Let's set our MariaDB service. This is a intial folder and files structure:

![mariadb setup](media/docker_mariadb/step_0.png)

> Note: MariaDB vs. MySQL - This projects uses MariaDB as required by subject, but you will see mysql in commands, paths, and configs (like mysqld, /var/lib/mysql, and mysql_install_db). This is normal, MariaDB is a drop-in replacement for MySQL, designed to work with the same commands and file structures. For all practical purposes in this guide, "MySQL" and "MariaDB" refer to the same database system.

What we need to do to set this container up is basically to install MariaDB package and client, create both MariaDB and MySQL configuration files and write a script that creates a database that will be used later by WordPress.

Here is a brief step-by-step for this Dockerfile, listed as ``KEYWORD`` : Idea:

- ``FROM`` : Get OS system image (as usual)
- ``ARG`` : Declare -parse- env variables that will be used later during the build
- ``RUN`` : Install mariadb and mariadb client.
- ``RUN`` : Create MySQL socket directory
- ``RUN`` : Configure MariaDB
- ``RUN`` : Init MariaDB database
- ``EXPOSE`` : Port to be used
- ``COPY`` : Copy mySQL database setup script
- ``RUN`` : Execute the just mentioned script
- ``CMD`` : Start mySQL server

Now, let's see a version of the full Dockerfile with comments to explain a bit deeper what is going on in each step:

```
# OS base image

FROM alpine:3.16

# Declare build arguments (these will be passed from .env by docker-compose.yml)

ARG DB_NAME
ARG DB_USER
ARG DB_PASS
ARG DB_ROOT

# Install MariaDB (update package index first and install both mariadb and client without cache)

RUN apk update && apk add --no-cache mariadb mariadb-client

# Create MySQL socket directory with correct permissions
# chown command sets ownership of the folder /var/run/mysqld to MariaDB (which it 'mysql' user)

RUN mkdir -p /var/run/mysqld && chown mysql:mysql /var/run/mysqld

# Configure MariaDB
# Directory '/etc/my.cnf.d' should exists after MariDB installation, but just in case, we can create it otherwise
# Echo writes the configuration into 'docker.cnf' file, using '\n' to have each option in newline
# 'docker.cnf' should not exist before this command, but if so, its content will be overwritten, so no worries there =)

RUN mkdir -p /etc/my.cnf.d && echo '[mysqld]\nskip-host-cache\nskip-name-resolve\nbind-address=0.0.0.0' > /etc/my.cnf.d/docker.cnf

# Disable skip-networking; needed in order to allow remote connections to the database (from another containers, for instance...)
# 'skip-networking' is a MariaDB/MySQL config option that disables all TCP/IP connections to the database and onlys allow local connections through Unix sockets
# Thus, we need to make sure this configuration is DISABLED
# We find and comment that option in '/etc/my.cnf.d/mariadb-server.cnf', using sed command with -i flag (modify file) and syntax 's/SEARCH/REPLACE/'

RUN sed -i 's/^skip-networking/#skip-networking/' /etc/my.cnf.d/mariadb-server.cnf

# Init MariaDB database: this command initializes a new MariaDB database by setting up the necessary files and system tables
# mysql_install_db creates basic structure of the database, as well as default tables
# --user==mysql flag ensures that all database files are owned by the mysql user
# --datadir=/var/lib/mysql flag tells MariaDB where to store its data, /var/lib/mysql is the default location tipaclly

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Informs Docker that the container will listen on port 3306 (MySQL default)

EXPOSE 3306

# Copy database setup script, which has been previosly stored in '/conf'

COPY conf/db.sh .

# Execute the script to create and init the database

RUN sh db.sh

USER mysql

# Start MySQL server

CMD ["/usr/bin/mysqld", "--skip-log-error"]
```

> The order of the lines in Dockefile is important, remember that they excute in descending order, adding "layers" or configurations to our image, so obviously you cannot change the permissions of a directory before creating that directory (silly simple example, sorry)

After Dockerfile is built, the image will have the directory `/var/lib/mysql`, which will have contain:

/var/lib/mysql/
│-- mysql/                 # System database (user accounts, privileges, etc.)
│-- performance_schema/     # Performance-related data
│-- information_schema/     # Metadata about databases
│-- ibdata1                # InnoDB system tablespace
│-- ib_logfile0, ib_logfile1 # InnoDB log files
│-- aria_log.*             # Aria storage engine logs
│-- *.frm, *.ibd, *.MYD, *.MYI # Table definitions and data


## Step 2. Script for creating a database

Now, our Dockerfile need a script that will be copied while building at then will be executed when the container starts. This script will create a mySQL database, let's get into it:

`vim requirements/mariadb/conf/db.sh`

Let's write the following code into it:

```
#!/bin/sh

# Check if MySQL system database exists

if [ ! -d "/var/lib/mysql/mysql" ]; then

	echo "Initializing MariaDB data directory..."
	chown -R mysql:mysql /var/lib/mysql

	# Init the database
	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

	tfile=$(mktemp)
	if [ ! -f "$tfile" ]; then
		echo "Error: Failed to create temp file."
		exit 1
	fi
fi

# Check if the WordPress database exists

if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then
	echo "Creating database and user..."

	cat << EOF > /tmp/create_db.sql
USE mysql;
FLUSH PRIVILEGES;

DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test';

DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT}';

CREATE DATABASE ${DB_NAME} CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASS}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

	# Run the SQL script to set up the database

	/usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db.sql
  if [ $? -ne 0 ]; then
    echo "Error: Failed to create database and user."
    exit 1
	fi
  rm -f /tmp/create_db.sql
fi
```

The first *if-fi* block of the script sets up a MariaDB only if it’s missing. It checks if the system database exists; if not, it initializes the data directory and system tables to ensure MariaDB can function. This prevents overwriting existing data, which is crucial when using persistent storage like Docker volumes, but we will get into that later on, do not worry.

Secon block to the same regarding WordPress, if its database is not found, the script creates it along with a user. It removes anonymous users, deletes the test database, restricts root access, and grants privileges to the new user. Finally, it applies changes and deletes the setup file, ensuring a secure and ready-to-use database.

## Step 3. Environment variables - Execute the script

To ensure the script runs correctly and the database is properly created, we must pass the necessary environment variables to the container.

Environment variables are kept separate from the project code, especially in open-source projects, for security reasons—a point emphasized throughout the subject.

Docker provides multiple ways to pass .env variables to a container. Here, we inject them via the Dockerfile, while docker-compose retrieves them from .env and passes them as build arguments. However, these variables do not persist in the final image—they exist only during the build process and are used to configure the database before being discarded. This is why the Dockerfile includes:

```
# Dockerfile
# Declare build arguments (these will be passed from the environment but NOT saved in the image)

ARG DB_NAME
ARG DB_USER
ARG DB_PASS
ARG DB_ROOT
```

## Step 4. Configuration of docker-compose

We continue to edit our docker-compose.yml, taking into account what we said about `.env` variables before.

```
  mariadb:
    build:
      context: ./requirements/mariadb
      dockerfile: Dockerfile
      args:
        DB_NAME: ${DB_NAME}
        DB_USER: ${DB_USER}
        DB_PASS: ${DB_PASS}
    container_name: mariadb
```
As we can see, our env variables are passed to ARG through the args section of the service `build:`

Let's not forget to mount the partition in the same way so that the database status is not reset after each container restart (do not worry about understanding volumes right now, we will get to that later)

```
    volumes:
      - db-volume:/var/lib/mysql
```

Also, at this point where we are starting to use volumes, we have to "declare" them not only within the service using the volumen itself, but also in the general scope of the docker-compose.yml -otherwise, the build will fail-. This has to be done bellow the services section of the file, and for now just declaring them will be enough (we will add some options later on)

```
#This goes at the very end of our current docker-compose.yml
volumes:
  db-volume:
```

Our current docker-compose.yml file should look like this:

```
version: '3'

services:
  nginx:
    build:
      context: ./requirements/nginx
      dockerfile: Dockerfile
    container_name: nginx
    ports:
      - "443:443"
  #  depends_on:
  #    - wordpress
    volumes:
      - ./requirements/nginx/conf/:/etc/nginx/http.d/
      - ./requirements/nginx/tools:/etc/nginx/ssl/
    restart: on-failure

  mariadb:
    build:
      context: ./requirements/mariadb
      dockerfile: Dockerfile
      args:
        DB_NAME: ${DB_NAME}
        DB_USER: ${DB_USER}
        DB_PASS: ${DB_PASS}
        DB_ROOT: ${DB_ROOT}
    container_name: mariadb
    volumes:
      - db-volume:/var/lib/mysql
    restart: on-failure

volumes:
  db-volume:
```

## Step 5. Checking the database status

Let's build and start the container:

```
# Being srcs/ directory
docker-compose up -d --build mariadb
```

In order to check if everything has worked out, run this command after starting the container:

``docker exec -it mariadb mysql -u root``

This way we will find ourselves in the text environment of the database.:

``MariaDB [(none)]> ``

Here we enter the command

``SHOW DATABASES;``

In our case, the output should be as follows:

```
+---------------------+
| Database            |
+---------------------+
| information_schema  |
| mydatabase          |  <<<< # There is our database
| mysql               |
| performance_schema  |
| sys                 |
+---------------------+
5 rows in set (0.001 sec)
```
There must be a database created by us with the name that you choose to place at the .env variable `DB_NAME`. If it doesn't exist, then our script worked incorrectly or didn't work at all. This may be due to a variety of reasons - the script file was not copied, the environment variables were not passed, the volumen being overwritten...

But if everything is done correctly, congratulations - we have successfully launched the database!

Exit MariaDB environment with the exit command or CTRL+D *Bye* and CTRL-D again if you want to exit docker container shell too.
