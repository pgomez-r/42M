# Creating a Makefile

According to the subject, Makefile is the only file that can be at the root of our repository, then the rest of files will be at srcs/. Then, let's start to do a basic Makefile.

When working with Docker, Makefiles are usually used to simplify long and complex commands or launch several processes and commands just with one rule.

The first variable of our Makefile will be the `name` variable; although this time it will only help to output logs, as we do not really generate an executable out of this Makefile

`NAME = inception`

### make all

Subject requires that one single Makefile rule will build and start the whole docker environment using docker-compose command. This command will be `docker-compose up`, but we will add some options (flags) to it, as follows:

`@docker-compose -f srcs/docker-compose.yml up -d --build`

Explained:

`-f` - specifies a custom path to the `docker-compose.yml` file

`-d` - 'detached mode', it runs containers in the background (so your terminal isn’t attached to logs)

`--build` - forces Docker to rebuild images (even if they already exist), ensuring the latest code/config is used; this option could be optional, or could be added for a different rule of the Makefile, such as ``make build`` for instance, but I rather force building with make all, that's up2you, as usual

Thus, our all section -which is the execution by default, when we run command make with no arguments- will look like this:

``
all:
@printf "Running the ${name} configuration...\n"
	@docker-compose -f srcs/docker-compose.yml up -d --build
``

### make down

The command ``docker-compose down`` command stops all containers found in the reference docker-compose.yml file. Again, we use -f option to specify a custom path to our docker-compose.yml, as it is not in the same folder as the Makefile.

``
down:
	@printf "Stopping ${NAME}...\n"
	@docker-compose -f srcs/docker-compose.yml down
``

> By the way, do not worry if you don't know or fully understand what a docker-compose.yml file is yet, you will get to know it a lot soon enough, no hurries!

### make clean

So how do you live without clean and fclean? Of course, these commands are much less useful in docker than in c, and the result of their work is not directly visible. However, if we want to clear the memory, delete unnecessary partitions and docker networks, they will be useful to us.

``docker system prune --a`` is a command that deletes all unused images

If we only need images of running containers, and all the others are already used, then by executing this command while the containers are running, we clear all unused images.

Creating a clean section:

```
clean: down
	@printf "Clearing the configuration of ${name}...\n"
	@docker system prune -a
```

## make fclean

Well, we can put a total cleanup on fclean. To clean up all the images that are on the machine, we will first stop all running containers with the command ``docker stop $$(docker ps -qa)`, then forcibly (with the --force flag) delete everything that is bad (and everything that is good too).

Next, we will delete all networks and all connected partitions. Our code will look like this:

``
fclean:
@printf "Complete cleanup of all docker configurations\n"
	@docker stop $$(docker ps -qa)
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force
``

It's worth doing `make fclean` only when you really want to build the entire make project from scratch.

Thus, our intial basic Makefile will look something like this:

```
NAME = inception

all:
	@printf "Building and setting configuration for ${NAME}...\n"
	@docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up -d --build

down:
	@printf "Stopping ${NAME}...\n"
	@docker-compose -f srcs/docker-compose.yml down

clean: down
	@printf "Stopping and cleaning up all docker configurations of ${NAME}...\n"
	@docker system prune -a

fclean:
	@printf "Complete cleanup of all docker configurations\n"
	@docker stop $$(docker ps -qa)
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force

re:	clean all

.PHONY	: all build down re clean fclean

```

Let's test this Makefile on our test container and then move on to the combat project!

> And don't forget to take a snapshot and save yourself in a cloud!
