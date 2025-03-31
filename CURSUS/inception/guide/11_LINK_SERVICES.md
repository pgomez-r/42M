# Link all services together - Volumes and Network

At this point we have each service working correctly by itself, but we are not finished quite yet, as some of them need to be connected to others. So, to finish the work, let's modify our docker-compose.yml to set this connections right. As for Dockerfiles, they all should be finished at this point, but we need to change the nginx configuration file as well to communicate to php and wordpress.

Also, we will upgrade our Makefile again after all the work is done, adding some useful steps and rules.

## Step 1. Update nginx configuration to work with WordPress

When we first set our nginx service, we left a basic version just to check that the server itself was working correclty. Now we need to change the configuration of nginx so that it processes only php files. 

To do this, we will remove any reference to html that we had before and replace them by php equivalent, add some lines to fix potential issues with WordPress and add a block that processes php.

Our updated `nginx.conf` file looks like this:

```
server {
    listen      443 ssl;
    server_name  <your_username>.42.fr www.<your_username>.42.fr;
    root    /var/www/html;
    index index.php;

    # SSL Configuration
    ssl_certificate     /etc/nginx/ssl/<your_username>.42.fr.crt;
    ssl_certificate_key /etc/nginx/ssl/<your_username>.42.fr.key;
    ssl_protocols       TLSv1.2 TLSv1.3;
    ssl_session_timeout 10m;
    keepalive_timeout 70;

    # WordPress Admin Specific Rules, sometimes needed to access your_wp_domain/wp-admin/
    location /wp-admin {
        try_files $uri $uri/ /wp-admin/index.php?$args;
    }

    # General PHP Handling
    location ~ \.php$ {
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        fastcgi_pass wordpress:9000;
        fastcgi_index index.php;
        include fastcgi_params;
        
        # Critical Fixes Below
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
        fastcgi_param HTTPS on;  # <-- This was missing
        fastcgi_param HTTP_X_FORWARDED_PROTO https;  # <-- This was missing
    }

    # General Request Handling
    location / {
        try_files $uri $uri/ /index.php?$args;
    }
}
```

> Again, we will need to replace all <your_username> with an real 42 nickname to make it work.

### Version of the file with explanation comments:

A bit more detailed...

```
server {
    # Listen on port 443 with SSL encryption
    listen      443 ssl;
    
    # Server names (replace <your_username> with actual username)
    server_name  <your_username>.42.fr www.<your_username>.42.fr;
    
    # Root directory for WordPress files
    root    /var/www/html;
    
    # Default index file to serve
    index index.php;

    # SSL Configuration
    ssl_certificate     /etc/nginx/ssl/<your_username>.42.fr.crt;  # Public certificate
    ssl_certificate_key /etc/nginx/ssl/<your_username>.42.fr.key;   # Private key
    ssl_protocols       TLSv1.2 TLSv1.3;                           # Allowed protocols
    ssl_session_timeout 10m;                                       # SSL session cache timeout
    keepalive_timeout 70;                                          # Keepalive connection timeout

    # WordPress Admin Specific Rules
    # Ensures proper routing for admin dashboard URLs
    location /wp-admin {
        try_files $uri $uri/ /wp-admin/index.php?$args;
    }

    # PHP Request Handling
    # Processes all PHP file requests through WordPress PHP-FPM container
    location ~ \.php$ {
        # Split the path info for proper script execution
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        
        # Forward to WordPress PHP-FPM container on port 9000
        fastcgi_pass wordpress:9000;
        
        # Default index file
        fastcgi_index index.php;
        
        # Include standard FastCGI parameters
        include fastcgi_params;
        
        # Critical Fixes Below
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;  # Set script filename
        fastcgi_param PATH_INFO $fastcgi_path_info;                        # Preserve path info
        fastcgi_param HTTPS on;                                            # Force HTTPS flag
        fastcgi_param HTTP_X_FORWARDED_PROTO https;                        # Proxy HTTPS indication
    }

    # General Request Handling
    # Fallback to index.php for pretty permalinks
    location / {
        try_files $uri $uri/ /index.php?$args;
    }
}
```

Now our configuration is finish and our nginx service is ready to serve our wordpress site to the localhost, let's move on.

## Step 2. Create and connect volumes and network

### Volumes

Docker volumes are a way to persist data and share it between containers or between a container and the host machine. Without volumes, when a container is stopped or deleted, all the data inside it is lost. Volumes allow you to store data outside the container, making it persistent and accessible even after the container is removed.

In this project, we are using *bind mounts*, which are a type of Docker volume that maps a specific directory on your host machine -your computer- to a directory inside the container. This allows for easy data sharing and persistence. Also, the subject requires the directory for storing all these volumes data to be located at `/home/<username>/data`.

For our services to work together, Nginx needs access to WordPress files (PHP scripts, themes, plugins...) to serve the website; and WordPress needs a place to store its data (posts, users, settings...), which will be the database handled by MariaDB.

Then, we need to create two volumes:

- wp-volume: sharing files Nginx <--> WordPress

- db-volume: storing/modifying files WordPress <--> MariaDB

To set this volumes we need to declare them in `docker-compose.yml`, name them, use the `o: bind` and `type: none` options so they become bind mounts, and also include the path of the 'reference' directory on the host machine, for example:

```
volumes:
  wp-volume:
    driver_opts:
      o: bind
      type: none
      device: /home/${USER}/data/wordpress

  db-volume:
    driver_opts:
      o: bind
      type: none
      device: /home/${USER}/data/mariadb
```

How would this work when our services are built and running? On your host machine, Docker wil use the specified local directories, then those will be mapped to the appropriate directories inside the containers. 

During running time, each service will write and/or read from each directory as needed, and when you stop or delete the containers, the data in `/home/${USER}/data/wordpress` and `/home/${USER}/data/mariadb` will remain intact.

When you restart the containers, they will use the same data, ensuring your website and database are preserved.

### Network

Next, we need to combine our containers into a single network. In fact, all containers that are registered inside the same single docker-compose.yml file are automatically combined into a common default network. 

However, we cannot name or set any options to this network, so we will create our own for convenience, so it can be accesible to us by name -and also, because the subject requires to do so...-

```
networks:
    inception:
        driver: bridge
```

## Updated docker-compose.yml

Let's update our docker-compose.yml to reflect the new volumes and the network in the services that need to. We will do this by adding some dependencies and options - remember that some of them were previously left to do-. Also, I am going to reorder the services so they follow the dependency order: mariadb(no dependecy) - wordpress(depens on mariadb) - nginx(depens on wordpress).

Our new file will look like this:

```
version: '3'

services:
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
    networks:
      - inception
    volumes:
      - db-volume:/var/lib/mysql
    restart: on-failure
    healthcheck:
      test: ["CMD", "mysqladmin", "ping", "-h", "localhost"]
      interval: 10s
      timeout: 5s
      retries: 5

  wordpress:
    build:
      context: ./requirements/wordpress
      dockerfile: Dockerfile
      args:
        DB_NAME: ${DB_NAME}
        DB_USER: ${DB_USER}
        DB_PASS: ${DB_PASS}
        DOMAIN_NAME: ${DOMAIN_NAME}
        WP_USER: ${WP_USER}
        WP_PASS: ${WP_PASS}
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
    networks:
      - inception
    volumes:
      - wp-volume:/var/www/html
    restart: on-failure

  nginx:
    build:
      context: ./requirements/nginx
      dockerfile: Dockerfile
    container_name: nginx
    depends_on:
     - wordpress
    ports:
      - "443:443"
    networks:
     - inception
    volumes:
      - ./requirements/nginx/conf/:/etc/nginx/http.d/
      - wp-volume:/var/www/html
    restart: on-failure

volumes:
  wp-volume:
    driver_opts:
      o: bind
      type: none
      device: /home/${USER}/data/wordpress

  db-volume:
    driver_opts:
      o: bind
      type: none
      device: /home/${USER}/data/mariadb

networks:
  inception:
    driver: bridge
```

*What has changed?* Aside from volumes and network -declaring them and specifying them on each service- we also added some small but important changes: 

- Healthcheck block for mariaDB, to make the *depends on condition* `service_healthy` truly work for Wordpress

```
  # Runs the command 'mysqladmin ping -h localhost' inside the MariaDB container to check if the database is responding. If the database is healthy, this command will return a success response. If not, after 5 retries the service will be considered crashed and so restarted.

  healthcheck:
    test: ["CMD", "mysqladmin", "ping", "-h", "localhost"]
    interval: 10s
    timeout: 5s
    retries: 5
```

- Nnginx change of volumes from the first version. Besides adding the 'wp-volume' (shared with wordpress service), we omit the previous 'ssl-volume', as we don't want potential overwritting, so we let nginx container to handle the certificates by itself (remember that the image building already copy or generate the certificate and place it where needed). Still, we keep the volume './requirements/nginx/conf/:/etc/nginx/http.d/' to have our nginx.conf file in image directory '/etc/nginx/http.d/'

```
    volumes:
      - ./requirements/nginx/conf/:/etc/nginx/http.d/
      - wp-volume:/var/www/html
```

At this point, if everything went right, our project should be totally functional, let's update our Makefile a bit and then we will be ready to test everything (*good luck!*)

## Step 3. Updating the Makefile

Our initial Makefile, while functional, could be a bit improved for some of the project requirements or utilities. 

Subject requires the volumes to be bound to `/home/<username>/data`, which we can manually create into or VM, but we can also add this step when using the make rule that will build and start our project. That way you protect yourself of potential issues if someone previously deleted those directories, for instance.

Same way, you may want to remove them if you want to do a totally clean restart for your project, step that we could include in the rule make fclean, or in another rule by itself if you prefer that way.

When doing both creating or deleting directories, use -p option to avoid rewritting any data and also protect the commands with if - fi blocks, otherwise you Makefile could find errors and stop before running the rest of the commands.

Also, as we mentioned several times before, the .env file is not allowed to be included in the repository when submitting the project for evaluation. There are several ways to obtain the file when evaluation begins, but I decided to add this step to the make all rule, which will download it from a previously generated url. This is not really a good practice in terms of security (although you could protect the url or the file with a password for better safety) but it is quite useful and convenient and as the day I am writing this, neither subject or evaluation page prohibit it in any way.

### Final version of Makefile

```
NAME = inception

all:
	@if [ ! -f srcs/.env ]; then \
		wget -O srcs/.env "https://drive.google.com/uc?export=download&id=YOUR_FILE_ID"; \
	fi
	@mkdir -p /home/${USER}/data
	@mkdir -p /home/${USER}/data/mariadb
	@mkdir -p /home/${USER}/data/wordpress
	@printf "Building and setting configuration for ${NAME}...\n"
	@docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up -d --build

down:
	@printf "Stopping ${NAME}...\n"
	@docker-compose -f srcs/docker-compose.yml down

clean: down
	@printf "Stopping and cleaning up all docker configurations of ${NAME}...\n"
	@docker system prune -a

fclean:
	@printf "Cleaning all configuration of ${NAME} and both volumes and host data...\n"
	@if [ -n "$$(docker ps -qa)" ]; then docker stop $$(docker ps -qa); fi
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force
	@docker image prune --all --force
	@docker container prune --force
	@docker builder prune --all --force
	@if [ -n "$$(docker volume ls -q)" ]; then docker volume rm $$(docker volume ls -q); fi
	@if [ -d "/home/${USER}/data" ]; then sudo rm -rf /home/${USER}/data; fi

re:	clean all

.PHONY	: all build down re clean fclean
```

I advise you to do a make clean before saving it to the cloud or anywhere, to keep it as lightest as possible.

This completes the main part of the project. After configuring wordpress, the project can be submitted. You also need to save all the sources to the repository and be able to correctly deploy your project from them.

> (!) When uploading to intra git repository DO REMEMBER TO LEAVE .env OUT OF IT (!)

# Step 4. Checking if all the configuration is working properly

So, after we run `docker-compose u --build` in our "~/project/srcs" directory, we will observe the configuration build for a while. And finally, we will find that everything is assembled and working.

Just in case, we will check the functionality of the configuration. Let's run a few commands. First, listen to the php socket:

``docker exec -it wordpress ps aux | grep 'php'``

The output should be similar as follows:

```
    1 root      0:00 {php-fpm8} php-fpm: master process (/etc/php8/php-fpm.conf
    9 nobody    0:00 {php-fpm8} php-fpm: pool www
   10 nobody    0:00 {php-fpm8} php-fpm: pool www
```

Then let's see how php works, having found out the version:

``docker exec -it wordpress php -v``

```
PHP 8.2.16 (cli) (built: Feb 21 2024 21:15:38) (NTS)
Copyright (c) The PHP Group
Zend Engine v4.2.16, Copyright (c) Zend Technologies
```

Finally, let's check if all the modules are installed.:

``docker exec -it wordpress php -m``

```
[PHP Modules]
Core
curl
date
dom
exif
fileinfo
filter
hash
json
libxml
mbstring
mysqli
mysqlnd
openssl
pcre
readline
Reflection
SPL
standard
xml
zip
zlib

[Zend Modules]
```

And that's it, if all these checks are OK and you can display your site on your browser, everything has been done -most probably- correctly. You still can check if volume data persists, the website behaves correctly, users are set properly, and many other tests.

In the next section you can find a list of test that you can have fun with before setting the project as finished, good luck!
