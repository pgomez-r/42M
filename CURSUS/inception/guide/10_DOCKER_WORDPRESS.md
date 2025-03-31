# Creating a wordpress container

For a general understanding, let's do a small review of the task, breaking it down into subtasks.

First, let's write out a list of what we need for the container:

- PhP with plugins for wordpress
- PhP-fpm for communication with nginx
- Wordpress itself

To get all done, we will need to perform the following steps:

- In Dockerfile: install php + plugins
- In Dockerfile: install wp-cli to be able to configure the core-install of wordpress later
- In Dockerfile: download and install wordpress at /var/www/html
- Insert the correct fastcgi config into the container (www.conf)
- Run a fastcgi container via a php-fpm socket


## Step 1. Setting up the Dockerfile

``vim requirements/wordpress/Dockerfile``

To start with, choose wich OS base image you want to use, in this guide we will be using Alpine.

Then, we will pass several arguments `ARG` from our .env file to the Dockerfile: the version of php -for convenience, as we will be using it in many commands and configurations-, the database info -name, user and pass-, the domain name for our website and the necessary info to create another WordPress user -username and pass-.

All these variables will be needed during the building of the image, but also for the wordpress setup script that will be executed in running time. As the `ARG` instruction only works for building-time, we will convert those into environment variables so the container has them when is up and running, by using the instruction `ENV`. *There is probably a smarter way to achieve this, but this approach is currently working, so far so good...* 

```
FROM alpine:3.18

ARG PHP_VERSION=82
ARG DB_NAME
ARG DB_USER
ARG DB_PASS
ARG DOMAIN_NAME
ARG WP_USER
ARG WP_PASS

ENV DB_NAME=$DB_NAME \
    DB_USER=$DB_USER \
    DB_PASS=$DB_PASS \
    DOMAIN_NAME=$DOMAIN_NAME \
    WP_USER=$WP_USER \
    WP_PASS=$WP_PASS
```

> Remember to add whatever of these variables to `inception/src/.env` if you do not have them yet, for example the second wordpress user:
``WP_USER=rick
WP_PASS=1234``

So now we have all the external info that our container needs for both buildind and running. Let's start the building by installing the basic php components: php itself, php-fpm for interacting with nginx and php-mysqli for interacting with mariadb.

```
RUN apk update && apk upgrade && apk add --no-cache \
    php${PHP_VERSION} \
    php${PHP_VERSION}-fpm \
    php${PHP_VERSION}-mysqli
```

Now let's check the wordpress documentation at the server environmnet section (https://make.wordpress.org/hosting/handbook/server-environment/) so we can see what packages we may need to install for Wordpress to work correctly, which would be:

- A web server; which we already have (nginx)

- PhP

- PhP extensions recommended, such as **curl, openssl, redis**...

- A database such as MariaDB -also, we already have that-.

If you read the full documentation page, you will notice that many php extensions packages are recommended; we are going to install only some of them. For the bonus part, we will also install the redis module -if not sure about doing the bonus part yet, you can install it aynway, it will do no harm-. We will also download the `wget` package needed to download wordpress itself, and the `unzip` package to unzip the archive with the downloaded wordpress.

> All this takes place in a single command line, using `RUN`. Why? Well, it would be more readable to write many `RUN` lines in our Dockerfile -and the final result will be the same-, but if you remember what we explain before, each command of Dockerfile adds a new layer to the image, then, the more layers, the bigger our image gets. Yes, the difference may be just some MBs, but it is a good practice keeping the image as lighter as possible, especially when building bigger projects.

Then, let's update our initial `RUN`instruction to add all these dependencies:

```
RUN apk update && apk upgrade && apk add --no-cache \
    php${PHP_VERSION} php${PHP_VERSION}-fpm php${PHP_VERSION}-phar \
    php${PHP_VERSION}-mysqli php${PHP_VERSION}-json \
    php${PHP_VERSION}-curl php${PHP_VERSION}-dom php${PHP_VERSION}-exif \
    php${PHP_VERSION}-fileinfo php${PHP_VERSION}-mbstring \
    php${PHP_VERSION}-openssl php${PHP_VERSION}-xml php${PHP_VERSION}-zip \
    php${PHP_VERSION}-redis wget unzip mysql-client && rm -rf /var/cache/apk/*
```

Next, we are going to make sure our container counts with the package `WP-CLI` (WordPress Command Line Interface), which is a tool that lets us manage WordPress without using a browser, and we will need to use it in run-time to setup or website

```
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp
```

Also, we can add a symlink for our php version path, just in case. Some scripts or tools might expect the PHP binary to be available at `/usr/bin/php`; this symlink ensures compatibility with such scripts or tools. This way, if we later use some commands or script that look for php default path -or if copy-paste from somewhere and forget to change it-, the symlink will point `/usr/bin/php` to the specific PHP version binary located at `/usr/bin/php${PHP_VERSION}` 

```
RUN ln -s /usr/bin/php${PHP_VERSION} /usr/bin/php
```

The next step is to modify wordpress configuration as we need. We will edit www.conf file so our fastcgi listens to all connections on port 9000.

The principle is the same as in the previous guide, we will use the `sed` command to change some specific lines of the config default file.

> (!) Path '/etc/php8/php-fpm.d/' depends on the installed php version!! You can use a variable PHP_VERSION or make sure of the path and specify it

```
RUN sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s|;listen.owner = nobody|listen.owner = nobody|g" /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s|;listen.group = nobody|listen.group = nobody|ig" /etc/php${PHP_VERSION}/php-fpm.d/www.conf
```

We need to download wordpress and unzip it along the path '/var/www/html'. For convenience, we will make this a working path with the `WORKDIR` dockerfile commmand. After assigning a working directory, we download the latest version of wordpress with wget, unzipp it, and delete all the source files.

Then we will copy and execute our configuration script, which will create the file `wp-config.php` and fill it with our desired cofiguration, as well as getting the information about or mariadb database. We will delete this script once finished and give full permissions to the wp-content folder so that our CMS can download themes, plugins, save images and other files.

```
WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.zip && \
    unzip latest.zip && \
    cp -rf wordpress/* . && \
    rm -rf wordpress latest.zip

COPY conf/wp-config.sh .
RUN sh wp-config.sh && rm wp-config.sh && chmod -R 0777 wp-content/
```

Next, we will do the same with another script, this one will automate the installation of WordPress and will setup the necessary services. This time we will only copy to the script to the desired folder in the image container, as *this script needs to be executed at run-time, not build-time(!)*

```
COPY conf/wp-setup.sh /usr/local/bin/wp-setup.sh

RUN chmod +x /usr/local/bin/wp-setup.sh
```

> We will see both scripts in more detail later in this same guide section.

Finally, expose the port and set CMD to execute or wp-config script and then run our installed php-fpm **(attention! the version must match the installed one!)**

```
EXPOSE 9000

CMD ["sh", "-c", "/usr/local/bin/wp-setup.sh && exec /usr/sbin/php-fpm82 -F"]
```

### Full Dockerfile example commented
```
# OS base image
FROM alpine:3.18

# Arguments needed by the image building process
ARG PHP_VERSION=82

ARG DB_NAME
ARG DB_USER
ARG DB_PASS

ARG DOMAIN_NAME
ARG WP_USER
ARG WP_PASS

# Convert args to environment variables for runtime (will be needed by the wp-setup script)
ENV DB_NAME=$DB_NAME \
    DB_USER=$DB_USER \
    DB_PASS=$DB_PASS \
    DOMAIN_NAME=$DOMAIN_NAME \
    WP_USER=$WP_USER \
    WP_PASS=$WP_PASS

# Install php and its main packages
# Install wget and unzip
# Clean cache after installation
# All this is a single line commmand, you can display as you prefer for better readability
RUN apk update && apk upgrade && apk add --no-cache \
    php${PHP_VERSION} php${PHP_VERSION}-fpm php${PHP_VERSION}-phar \
    php${PHP_VERSION}-mysqli php${PHP_VERSION}-json \
    php${PHP_VERSION}-curl php${PHP_VERSION}-dom php${PHP_VERSION}-exif \
    php${PHP_VERSION}-fileinfo php${PHP_VERSION}-mbstring \
    php${PHP_VERSION}-openssl php${PHP_VERSION}-xml php${PHP_VERSION}-zip \
    php${PHP_VERSION}-redis wget unzip mysql-client && rm -rf /var/cache/apk/*

# Install WP-CLI (to be used later in WordPress setup script)
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Create a symlink for php binary, so any call to php will be redirected to php<used_version>: in our case, php82
RUN ln -s /usr/bin/php${PHP_VERSION} /usr/bin/php

# Verify PHP installation before running wp-setup.sh
RUN php -v

# Modify PHP-FPM configuration
RUN sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s|;listen.owner = nobody|listen.owner = nobody|g" /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s|;listen.group = nobody|listen.group = nobody|ig" /etc/php${PHP_VERSION}/php-fpm.d/www.conf

# Set working directory
WORKDIR /var/www/html

# Download, unzip wordpress latest version (check on website and change according)
# Move wordpress folder to working directry (/var/www/html)
# Remove the .zip file that you don't need any more, keeping the image lighter
RUN wget -O wordpress.zip https://wordpress.org/wordpress-6.5.2.zip && \
    unzip wordpress.zip && \
    cp -rf wordpress/* . && \
    rm -rf wordpress wordpress.zip

# Copy script from project folder to image, which will be used to generate the wp-config.php
COPY conf/wp-config.sh .

# Execute script, remove it after and give all persmissions to wp-content folder
RUN sh wp-config.sh && rm wp-config.sh && chmod -R 0777 wp-content/

# Copy script to automate the installation of WordPress and setup of necessary services
COPY conf/wp-setup.sh /usr/local/bin/wp-setup.sh
RUN chmod +x /usr/local/bin/wp-setup.sh

EXPOSE 9000

# Start php-fpm service in the foreground and run wp-setup.sh
CMD ["sh", "-c", "/usr/local/bin/wp-setup.sh && exec /usr/sbin/php-fpm82 -F"]
```

## Step 2. Configuration of docker-compose

Now let's add a wordpress service to our docker-compose following the same basic pattern to start, as we have done before:

```
  wordpress:
    build:
      context: ./requirements/wordpress
      dockerfile: Dockerfile
    container_name: wordpress
    depends_on:
      mariadb:
       condition: service_healthy
    restart: on-failure
```

The `depends_on` directive means that wordpress depends on mariadb, and will not start until the database container is assembled. We need to ensure this because wordpress will need the database to be fully created in order to work correctly.

Even using `depends_on`, both services MariaDB and WP may be built and assembled at about the same time, so in order to make really sure this will not happen, adding the condition `service_healthy` it is also a good practice.

> *Also, it helps to organize the docker-compose file in the desired order of building: mariadb(no dependency) - wordpress(depends on mariadb) - nginx(depends on wordpress)*

Next, we will pass our evironment variables -from .env file- to the container as both arguments for building and environment for running-time:

```
  wordpress:
    build:
      context: ./requirements/wordpress
      dockerfile: Dockerfile
      args:
        DB_NAME: ${DB_NAME}
        DB_USER: ${DB_USER}
        DB_PASS: ${DB_PASS}
    container_name: wordpress
    environment:
    - DB_NAME=${DB_NAME}
    - DB_USER=${DB_USER}
    - DB_PASS=${DB_PASS}
    - DOMAIN_NAME=${DOMAIN_NAME}
    - WP_USER=${WP_USER}
    - WP_PASS=${WP_PASS}
    depends_on:
      mariadb:
       condition: service_healthy
    restart: on-failure
```

> (i) Notice that .env variables as arguments for Dockerfile are inside block 'build:', but when setting them as environment variables for the running-time of the container, they are on a block by itself called 'environment:'

We could -and indeed will need- to add more lines to wordpress docker-compose block in order to make it work. In the case of WordPress container, we will not be able to launch it at a basic state to test it so easily as we have done before with nginx and mariaDB, but for now let's leave the docker-compose.yml as it is, we will get everything done in the next guide section and then we will be able to view or website at last.

## Step 3. Worpdress pre-configuration script

We will need to copy our own configuration file to the wordpress folder, which will also connect to the database. We will do so by creating a script that will insert the lines into the desired file.

``
mkdir inception/srcs/requirements/wordpress/conf

vim inception/srcs/requirements/wordpress/conf/wp-config.sh
``

Basically, what the script needs to do is:
- Checks if /var/www/html/wp-config.php exists (in case we already set it, to avoid rewritting it)
- If not, it creates the file and populates it with the WordPress configuration.
- It pulls database credentials from environment variables.
- Finally, it includes wp-settings.php to complete the WordPress setup.

Here is an example of a script to this, with explaining comments:

```
#!/bin/sh

# Check if wp-config.php doesn't exist in WordPress root directory
if [ ! -f "/var/www/html/wp-config.php" ]; then
    # Use heredoc to create wp-config.php with dynamic values from environment variables
    cat << EOF > /var/www/html/wp-config.php
<?php
# Database connection settings
define( 'DB_NAME', '${DB_NAME}' );          # Database name from environment variable
define( 'DB_USER', '${DB_USER}' );          # Database user from environment variable
define( 'DB_PASSWORD', '${DB_PASS}' );      # Database password from environment variable
define( 'DB_HOST', 'mariadb' );             # Hostname of MariaDB container (Docker service name)
define( 'DB_CHARSET', 'utf8' );             # Default database charset
define( 'DB_COLLATE', '' );                 # No custom collation

# Filesystem method - allows direct filesystem writes (needed for Docker)
define('FS_METHOD','direct');

# Force SSL for admin area and detect HTTPS from proxy headers
define('FORCE_SSL_ADMIN', true);
if (isset(\$_SERVER['HTTP_X_FORWARDED_PROTO']) && \$_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
    \$_SERVER['HTTPS'] = 'on';  # Set HTTPS flag when behind a proxy with SSL termination
}

# WordPress database table prefix (change for security)
\$table_prefix = 'wp_';

# Debug mode - disabled in production
define( 'WP_DEBUG', false );

# Define absolute path to WordPress directory
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

# Load WordPress settings
require_once ABSPATH . 'wp-settings.php';
EOF

    echo "wp-config.php created successfully."
else
    echo "wp-config.php already exists. Skipping creation."
fi
```

> *Let's pay attention to `\$table_prefix = 'wp_';` The backslash - "\\" is used so shell will not interpret `$table_prefix` as a varaible to be expanded -which would result in an empty string-. `$table_prefix` is meant meant for PHP, not the shell*

## Step 4. WordPress installation and setup script

If we would only do the pre-configuration of WordPress, using the previous script, our CMS will have the essential data and info to be working properly, but the website itself would not be displayable yet. In that scenario, once the container is built and running, the first time we open our domain in a browser we would be welcomed by WordPress Installation Wizard -the installation page- that would ask us to set some info, such as admin email, site title, etc.

This is not totally wrong, we could set the page the first time in this manner, but it is forbidden by the subject... So, let's do the same with a script that will be executed first thing as soon as the container is up and running, and which will automate the installation of WordPress and setup of necessary services.

The main steps of the script:
- Checks if the intended configuration for you website has been already done (it may happen once we have persistent volumes set up correctly)
- Checks that all necesary pre-requisites are properly installed (wp-cli, wordpress itself, php, database...) If not, we will get error messages showing what has failed. **Hopefully, we won't need this, but if we do, these debug prints may be helpful.**
- Wait for database to be ready with a sleep/try loop. Again, another protection just in case, we should not have this problem, as the container itself waits for mariadb to be healthy before starting.
- Use WP-CLI to install WordPress, specifying configurations such as the site URL, admin - credentials, and WordPress path.
- Create a new WordPress User -only if not existing yet- with a specified role and credentials.

Here is an example of a script to do all of this:

```
#!/bin/sh

# =============================================
# Early Exit Check - If WordPress is fully configured
# =============================================
if [ -f /var/www/html/wp-config.php ] && 
   wp core is-installed --allow-root --path="/var/www/html" && 
   wp user get "$WP_USER" --allow-root --path="/var/www/html" &>/dev/null; then
    echo "WordPress is already fully configured. Exiting setup."
    exit 0
fi

# =============================================
# Normal Setup Process (Only runs if not configured)
# =============================================

# Verify WP-CLI is installed
if ! command -v wp > /dev/null 2>&1; then
    echo "Error: WP-CLI (wp command) is not installed"
    exit 1
fi

# Verify WordPress files exist
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Error: WordPress files not found in /var/www/html"
    exit 1
fi

# Check if PHP is installed
if ! command -v php > /dev/null 2>&1; then
    echo "PHP is not installed. Exiting."
    exit 1
fi

echo "Creating setup with the following values:"
echo "DB_NAME: ${DB_NAME}"
echo "DB_USER: ${DB_USER}"
echo "DB_PASS: ${DB_PASS}"

# Wait for MariaDB to be ready
MAX_RETRIES=5
RETRY_COUNT=0
until mysql -h mariadb -u"${DB_USER}" -p"${DB_PASS}" -e "USE ${DB_NAME};" 2>/dev/null; do
    RETRY_COUNT=$((RETRY_COUNT+1))
    if [ $RETRY_COUNT -ge $MAX_RETRIES ]; then
        echo "Error: Could not connect to MariaDB after $MAX_RETRIES attempts"
        echo "Trying command: mysql -h mariadb -u${DB_USER} -p[hidden] -e \"USE ${DB_NAME};\""
        mysql -h mariadb -u"${DB_USER}" -p"${DB_PASS}" -e "USE ${DB_NAME};"
        exit 1
    fi
    echo "Waiting for MariaDB... (attempt $RETRY_COUNT/$MAX_RETRIES)"
    sleep 5
done

echo "Database ready. Proceeding with WordPress setup..."

# Only run core install if WordPress isn't already installed
if ! wp core is-installed --allow-root --path="/var/www/html"; then
    echo "Running WordPress core installation..."
    wp core install --allow-root \
        --url="https://$DOMAIN_NAME" \
        --title="pgomez-r inception" \
        --admin_user="$DB_USER" \
        --admin_password="$DB_PASS" \
        --admin_email="pedrogruz.11@gmail.com" \
        --path="/var/www/html"
    if [ $? -ne 0 ]; then
        echo "Error: wp core install failed."
        exit 1
    fi
else
    echo "WordPress is already installed. Skipping core installation."
fi

# Only create user if it doesn't exist
if ! wp user list --allow-root --path="/var/www/html" | grep -q "^\s*[0-9]\+\s\+$WP_USER\s"; then
    echo "Creating WordPress user '$WP_USER'..."
    wp user create "$WP_USER" "guest@example.com" \
        --role=author \
        --user_pass="$WP_PASS" \
        --allow-root \
        --path="/var/www/html"
    [ $? -ne 0 ] && echo "Error: Failed to create user" && exit 1
else
    echo "User '$WP_USER' already exists. Skipping creation."
fi

echo "WordPress setup completed successfully."
```

Congratulations, we have completed the installation and configuration of our wordpress. Now let's move to the last section of the guide about mandatory part, where we will connect all services, volumes and network.
