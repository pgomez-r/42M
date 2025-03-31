NAME = inception

all:
	@if [ ! -f srcs/.env ]; then \
		wget -O srcs/.env "https://drive.google.com/uc?export=download&id=1SpzVU24F5Q26y-N3IjPPb1fhfn0Y1wYU"; \
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
