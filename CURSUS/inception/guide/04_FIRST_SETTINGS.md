# Pre-configuring Docker

> Don't forget to take a snapshot of the status before each new stage of the build!

## Step 1. Installation and configuration of sudo

Now we need to start working with docker. First, let's make it convenient for us, as well as test its operation.

> It is better to perform all the actions of this guide through the terminal or the VSCode ssh remote extension, so that it is possible to copy-paste commands and code

By default, docker is run either with superuser privilege, or by any user in the docker group who has the ability to make requests under superuser (for example, via sudo). 

(Previously, we installed the sudo utility, which allows the user to make requests as root)

In order for our user to make such requests in the system, we edit the /etc/sudoers config.:

```vim /etc/sudoers```

Our task is to add an entry with our user name and rights equivalent to root rights.:

![Docker Configuration](media/setting_docker/step_5.png)

![Docker Configuration](media/setting_docker/step_6.png)

Save the changes and close the file.

## Step 2. Adding a user to the docker group

Now let's add our user to the ``docker`` group. This will allow us to execute docker commands without having to invoke sudo. (yes, we installed sudo not for docker, but for the convenience of working with the system).

This is what our user's group list looks like now.:

 ```groups <your_nickname>```

![Setting up Docker](media/setting_docker/step_0.png)

Let's add our user to the group with the command 

```sudo usermod -aG docker <your_nickname>```

And check that the addition has occurred.:

```groups <your_nickname>```

![Setting up Docker](media/setting_docker/step_1.png)

As we can see, the docker group has been added to the list of groups at the very end. This means that now we can call our docker from under a regular user

So let's switch to our user and go to his home directory

```su <your_nickname>```

```cd ~/```

## Step 3. Create project directories and files

Next, we need to create some directories and files according to the subject.

This is a routine task in which there is nothing complicated: you can create them on file manager, VSCode if ssh connected or with the terminal commands `mkdir`, `touch`... and so on. 

If you want to do this quicker, the author of the reference guide made a script called ``make_directories.sh``, which performs all these actions automatically and which is placed at the same directory of this guide. If you are going use it, you should edit it and add your nickname or change any folder name if wanted.

``nano make_directories.sh``

Here is its code, in case you don't have the file you can just create one and copy this:

```
#!/bin/bash
mkdir project
mkdir project/srcs
touch project/Makefile
mkdir project/srcs/requirements
touch project/srcs/docker-compose.yml
touch project/srcs/.env
echo "DOMAIN_NAME=<your_nickname>.42.fr" > project/srcs/.env
echo "CERT_=./requirements/tools/<your_nickname>.42.fr.crt" >> project/srcs/.env
echo "KEY_=./requirements/tools/<your_nickname>.42.fr.key" >> project/srcs/.env
echo "DB_NAME=wordpress" >> project/srcs/.env
echo "DB_ROOT=rootpass" >> project/srcs/.env
echo "DB_USER=wpuser" >> project/srcs/.env
echo "DB_PASS=wppass" >> project/srcs/.env
mkdir project/srcs/requirements/bonus
mkdir project/srcs/requirements/mariadb
mkdir project/srcs/requirements/mariadb/conf
touch project/srcs/requirements/mariadb/conf/create_db.sh
mkdir project/srcs/requirements/mariadb/tools
echo "" > project/srcs/requirements/mariadb/tools/.gitkeep
touch project/srcs/requirements/mariadb/Dockerfile
touch project/srcs/requirements/mariadb/.dockerignore
echo ".git" > project/srcs/requirements/mariadb/.dockerignore
echo ".env" >> project/srcs/requirements/mariadb/.dockerignore
mkdir project/srcs/requirements/nginx
mkdir project/srcs/requirements/nginx/conf
touch project/srcs/requirements/nginx/conf/nginx.conf
mkdir project/srcs/requirements/nginx/tools
touch project/srcs/requirements/nginx/Dockerfile
echo ".git" > project/srcs/requirements/nginx/.dockerignore
echo ".env" >> project/srcs/requirements/nginx/.dockerignore
mkdir project/srcs/requirements/tools
mkdir project/srcs/requirements/wordpress
mkdir project/srcs/requirements/wordpress/conf
touch project/srcs/requirements/wordpress/conf/wp-config-create.sh
mkdir project/srcs/requirements/wordpress/tools
echo "" > project/srcs/requirements/wordpress/tools/.gitkeep
touch project/srcs/requirements/wordpress/Dockerfile
echo ".git" > project/srcs/requirements/wordpress/.dockerignore
echo ".env" >> project/srcs/requirements/wordpress/.dockerignore
```

> Don't forget to change <your_nickname> to your nickname!

To execute the script, it must be given permission:
`chmod +x make_directories.sh `

![Setting up Docker](media/setting_docker/step_7.png)

After that, you can run it.:

``./make_directories.sh``

And that's it, all the directories of our project (and even some necessary files in them) have been created!
