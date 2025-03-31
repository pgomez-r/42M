# Creating NIGNX container

As we said before, the idea of this guide is to first set each service container by itself, so it doesn't really matter which one you start with, there will be a final section of the guide to connect and finish all of them together.

Let's begin here with nginx.

## Step 1. Create a Dockerfile

As we learnt before, `Dockerfile` is responsible for the configuration of the image, so let's create or nginx Dockerfile on its folder:

`vim ~/project/srcs/requirements/nginx/Dockerfile`

Then we first write on it the `FROM` instruction, which indicates from which OS image we will deploy our container. By subject, we are prohibited from specifying labels like `latest`, which are automatically assigned to the latest versions of the system in the dockerhub repositories. Therefore, we go to the official website of the system you chose and see which is the penultimate stable version.

```FROM debian:bullseye```

> More information about Dockerfile instructions can be found in [this video](https://www.youtube.com/watch?v=wskg5903K8I "docker by Anton Pavlenko"), here we will analyze just a few of them.

Next, we specify which software and how we want to install it inside the container. The `RUN` instruction will help us with this.

The `RUN` instruction creates a new image layer with the result of the called command, similar to how the snapshot system saves changes in a virtual machine. Actually, the image itself consists of this kind of layers of changes, which are written to the image, but RUN instruction do not execute anything -despite its name-, `CMD` and `ENTRYPOINT` do run something, but they DO NOT WRITE changes to the image. A bit confusing at first, I know.

We can say that the changes made through `RUN` are static and it is like the setup we do at first in a VM, installing packages and setting configuration files, as a container is essentially a super-light VM. For example, installing nginx and ceritifacte packages in the container could be done like this:

`RUN apt-get update && apt-get install -y nginx openssl`

Another way to set or change configurations in a container image is to copy files into in when building, when this is happening you can get files from the host machine -if path is properly specified, obviously- and copy into the final image directories:

```COPY conf/nginx.conf /etc/nginx/sites-available/default```

That would place a file -that we will create later on this section- to have stored in our project folder before deploy, although we could also create and write the file directly in the building process with something like:

```RUN echo 'whatever_config_content_we_need' > etc/nginx/sites-available/default/nginx.conf` ```

Just to easily test if the service is working, we will add a simple .html file to be served by nginx, so we can display in localhost when the container is up and running -not part of the subject, we will change it later-. Create the file with any content you want and place it at `srcs/nginx`, then write in Dockerfile:

```COPY index.html /var/www/html/index.html```

> Alternatively, you cand directly create an fill the file with 'RUN touch /var/www/html/index.html && echo "<h1>Nginx is working!</h1>" > /var/www/html/index.html'

As we said before, subject enforces us to use SSL certificate for our website and nginx, as the server of the website, will be the reponsible for it. To do so, we can either have the certificate generated and store in the VM system, and the copy it to the image, or we could directly generate the certificate itself during the building stage of the image.

```
# Copy our certificates into nginx ssl certificates directory
COPY <your_local_directory>/pgomez-r.42.fr.crt /etc/nginx/ssl/pgomez-r.42.fr.crt
COPY <your_local_directory>/pgomez-r.42.fr.key /etc/nginx/ssl/pgomez-r.42.fr.key
```

```
# Generate ssl certificate and key during building stage
RUN openssl req -subj "/C=SP/ST=Malaga/L=Malaga/O=42 Malaga/OU=pgomez-r/CN=pgomez-r" \
    -new -newkey rsa:2048 -days 365 -nodes -x509 \
    -keyout /etc/nginx/ssl/pgomez-r.42.fr.key -out /etc/nginx/ssl/pgomez-r.42.fr.crt
```

Next, we will use the `EXPOSE` instruction. At first glance, the EXPOSE command in a Dockerfile might seem pointless —it doesn’t actually publish ports or change how the container runs. But it serves two key purposes: documentation (declares which ports the container intends to use) and to work with -P (Auto-Publish Ports); when you run the container with `docker run -P`, Docker automatically maps all EXPOSEd ports to random host ports.

```EXPOSE 443```

At the end of the file we have to run the installed configuration. To do this, use the instruction ``CMD``, which defines the default command to run when the container starts:

```CMD ["nginx", "-g", "daemon off;"]```

This way we run nginx directly, rather than in daemon mode. Daemon mode, on the other hand, is a startup mode in which an application starts in the background, or as in Windows equivalence, a service. For the convenience of debugging, we disable this mode and receive all nginx logs directly into the tty of the container (-g flag).

### Full Dockerfile example

Here is an commented example of our initial version of Dockerfile for nginx:

```
# OS base image
FROM debian:bullseye

# Install nginx package, plus openssl and ca-certificates so we can read/use our .crt and .key
RUN apt-get update && apt-get install -y nginx openssl

# Set nginx configuration by copying our own .conf file in default configuration directory
COPY conf/nginx.conf /etc/nginx/sites-available/default

# Generate ssl certificate and key
RUN openssl req -subj "/C=SP/ST=Malaga/L=Malaga/O=42 Malaga/OU=pgomez-r/CN=pgomez-r" \
    -new -newkey rsa:2048 -days 365 -nodes -x509 \
    -keyout /etc/nginx/ssl/pgomez-r.42.fr.key -out /etc/nginx/ssl/pgomez-r.42.fr.crt

# Create a basic index.html in the index directory used by our config, so we can test if the server is working properly
# We will change this later, when wordpress is set and working
RUN touch /var/www/html/index.html && echo "<h1>Nginx is working!</h1>" > /var/www/html/index.html

EXPOSE 443

# CMD to be executed when docker-compose, to run nginx without daemon "mode"
CMD ["nginx", "-g", "daemon off;"]
```

## Step 2. Create a configuration file

Naturally, our nginx won't work without a configuration file. We need to create a config file in our project so Dockerfile can copy it to the image and place it in the right target directory when building.

``mkdir conf && vim conf/nginx.conf``

Here is an example of a working **-or should be working-** nginx.conf file, with explaning comments:

```
# Define a server block to handle requests
server {
    # Listen on port 443 for HTTPS connections with SSL/TLS enabled
    listen      443 ssl;

    # Specify the server name (domain) that this block will respond to
    server_name  <your_username>.42.fr www.<your_username>.42.fr;

    # Define the root directory where the website files are stored
    root    /var/www/html;

    # Set the default file to serve when a directory is requested
    index index.html; # We will change this to index.php when WordPress is ready

    # Specify the path to the SSL certificate file and key
    ssl_certificate     /etc/nginx/ssl/<your_username>.42.fr.crt;
    ssl_certificate_key /etc/nginx/ssl/<your_username>.42.fr.key;

    # Define the SSL protocols that are allowed (TLS 1.2 and 1.3)
    ssl_protocols       TLSv1.2 TLSv1.3;

    # Set the timeout for SSL sessions to 10 minutes and keepalive timeout to 70 seconds
    ssl_session_timeout 10m;
    keepalive_timeout 70;

    # Define a location block to handle requests to the root URL path (/)
    location / {
        # Set the default file to serve when a directory is requested
        index index.html; # TODO: Change this to index.php when WordPress is ready

        # Try to serve the requested file, if not found, pass the request to index.html with the query arguments
        try_files $uri /index.html?$args; # TODO: Change to index.php when WordPress is ready

        # Add a custom header indicating the last modification date of the resource
        add_header Last-Modified $date_gmt;

        # Add a Cache-Control header to prevent caching of the content
        add_header Cache-Control 'no-store, no-cache';

        # Disable the If-Modified-Since header to prevent conditional requests
        if_modified_since off;

        # Disable expiration headers
        expires off;

        # Disable ETag headers
        etag off;
    }

# Later, once php and wordpress are set,we will add another block here to handle php and fastcgi as well and modify or even omitt some of these current settings

```

> (!) Remember to replace <your_username> for your actual 42intra login

> Later, on [guide 11](https://github.com/pgomez-r/inception/tree/main/guide/10_LINK_SERVICES.md "Link Services"), we will provide a final version of this configuration file, for now we should not worry much about it as long as the server itself works with our simple html file.

## Step 3. Creating the docker-compose configuration

Docker-compose is a docker container launch system, which can be said to be a kind of add-on to docker. If we specified in docker files which software to install inside a single container environment, then with docker-compose we can manage the launch of many similar containers at once, launching them with a single command.

To do this we must edit our already created docker-compose.yml file in the root of our project.

First, we register the version. The latest version is the third one.

We will create a block for services, being 'nginx' the first on the list. 

```
version: '3'

services:
  nginx:
```

> (!) We have to use spaces (**not tabs(!)**) to indent on docker-compose.yml files

In the next indent level of the nginx service we specify the `build:` which will have several elements or propierties within (within another indent level). 

`context` is kind of your workspace root directory, the path from where to start to look for the Dockerfile and files needed by this. Then you can specify the Dockerfile in that directory `dockerfile: Dockerfile`. If you use '.' as context, your root will be the folder where `docker-compose.yml` is placed, in our case `srcs`; this could be helpful to have access to all service folders from any Dockerfile -e.g., nginx Dockerfile may need COPY files from wordpress/- But in my case, I decided to keep the context on each service folder, the decision is up to you.

```
version: '3'

services:
  nginx:
    build:
      context: ./requirements/nginx
      dockerfile: Dockerfile
```

We set a name for our container, as well as forward the required port (in this project we can only use 443 port - standard for https).

We will also describe the dependency, while commenting it out. We need nginx to start after wordpress, picking up its build. But nginx builds faster, and in order to avoid collisions, we need it to wait for the wordpress container to be built and run only after it, that's the use of `depends_on`. For now, we'll comment on this as we don't have wordpress yet, also we will see others ways to ensure the depens on function with more options later on.

```
version: '3'

services:
  nginx:
    build:
      context: .
      dockerfile: requirements/nginx/Dockerfile
    container_name: nginx
#    depends_on:
#      - wordpress
    ports:
      - "443:443"
```

We add sections so that the container sees our config and our keys, and we also make sure to mount our /var/www/html - the same folder from the old configuration that we will need for the nginx trial run. Later, we will delete it and take files from the wordpress directory.

```
version: '3'

services:
  nginx:
    build:
      context: .
      dockerfile: requirements/nginx/Dockerfile
    container_name: nginx
#    depends_on:
#      - wordpress
    ports:
      - "443:443"
    volumes:
      - ./requirements/nginx/conf/:/etc/nginx/http.d/
      - ./requirements/nginx/tools:/etc/nginx/ssl/
```

Next, we specify the type of restart. In this case I am using "on failure":

```
    restart: on failure
```

This is an example of our intial docker-compose.yml file for nginx

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
```

Let's launch our new configuration:

```cd ~/project/srcs/```

```docker-compose build nginx```

```docker-compose up -d nginx```

> You can also replace that step by just running 'make' command in project root directory, but that would build and compose up all containers, so I think it is good to see how to build and run only one specific container, as you will most probably need to do so while developing and testing each one

Now, try to open in browser:

``https://127.0.0.1 `` or ``https://<your_username>.42.fr``

And now, if we access the localhost from the browser, we get a working configuration.:

![nginx worker](media/install_certificate/step_10.png)

By easily replacing several docker-compose values and uncomenting the configuration file, we will get a working nginx that supports TLS and works with wordpress. But that is going to happen next.

In the meantime, we take snapshots, save ourselves in the cloud, pour a pleasant liquid for the body and enjoy life.
