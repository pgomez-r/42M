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