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
# chown command sets ownership of the folder /var/run/mysqld to MariaDB (which is 'mysql' user)
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
CMD ["mysqld", "--skip-log-error"]
