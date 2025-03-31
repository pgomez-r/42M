# INCEPTION EVAL_LIST

A list of tests to be checked before you set the project as finished and submit it for evaluation. In order to gather these, I have inspected both subject and evaluation requirements and then included any tests or cases that came to my mind while doing so.

- [ ]  The project must be deployed on a VM, pretty obvious…

### ***Let’s start the installation***

- [ ]  Before starting the evaluation, run this command in the VM terminal: `docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q) 2>/dev/null` - This will forcefully remove **all Docker containers, images, volumes, and networks** from your system; a complete clean-up before starting the evaluation.
- [ ]  Check Makefile → it must deploy the entire environment and application with one single command which will also use docker-compose.yml to do this. Inspect the checkfile for this rule, let the evaluated student to explain it to you and then run `make` or `make <rule>`

Here, the installation should begin, which may take some time, so let’s continue the evaluation by ***inspecting all folder and file***s in the meantime…

### About ***credentials, secrets, environment*** and other condifential information

- [ ]  Environment variables, secrets, keys, certificates or any other confidential information *must be kept outside the git repository* uploaded to the intra for evaluation - Search on the repository for '.env', 'cert', 'key'...
- [ ]  Passwords must not be present in your Dockerfiles - Search on each Dockerfile for any occurencies of 'pass', 'password', 'secret', 'key' and so on, and verify that in all occurencies, the value of the variables are passed as env variables or arguments.
- [ ]  The use of environment variables is mandatory - Check that docker-compose.yml and Dockerfile(s) handle and use them

### About ***project folder structure***

- [ ]  Inspect the project folder tree;  all files must be placed in srcs/, except from Makefile, as for example
    
    ```bash
      ```
              Makefile
              srcs/
                  (.env) # This file MUST not be in intra repository(!)
                  docker-compose.yml
                  requirements/
                      mariadb/
                      nginx/
                      wordpress/
      ```
    ```
    

### Let’s inspect ***docker-compose.yml overall aspects***

- [ ]  Inspect docker-compose.yml field `container_name` → each Docker image must have the same name as its corresponding service
- [ ]  Inspect docker-compose.yml → each service has to run in a dedicated container, check if there are three separated blocks inside `service:`, one per service
- [ ]  There is a volume that contains WordPress database
- [ ]  There is a volume that contains WordPress website files
- [ ]  There is a docker-network that establishes the connection between your containers
- [ ]  Using `network: host` or `-link` or `links:` in docker-compose.yml is forbidden - Again, try to search on file or find in folder for any occurencies

### About the ***Dockerfiles overall aspects***

- [ ]  There must be one Dockerfile per service - Check the folder tree to see that each service folder has one only Dockerfile
- [ ]  At the same time, there can be only one service-related package per Dockerfile → nginx Dockerfile may not install WordPress or MariaDB in its image, MariaDB Dockerfile may not install nginx package, and so on…
- [ ]  Docker images must be built from the ***penultimate stable version*** of ***Alpine or Debian*** - check in each Dockerfile that: 1) FROM uses either ALPINE or DEBIAN; 2) The version used in each case is the penultimate stable version according to official site of the OS
- [ ]  Dockerfiles have to been written by the student itself; it is forbidden to use ready-made ones or to use services such as the ones in DockerHub - *don’t really know how to check this for sure -*
- [ ]  Any use of `tail -f` and similar methods when running containers are *forbidden* - Try to `find in folder` for srcs/ with the words `tail -f`, if any found, project evaluation is failed
- [ ]  Containers must not be started with a command running an infinite loop; this also applies to any command used as entrypoint, or used in entrypoint scripts - To check all of this, `find in folder` at srcs/ for the words `tail -f`, `bash`, `sleep infinity`, `while true`
- [ ]  The `latest` tag is prohibited - Check this by searching on file or finding in folder for any occurencies of it
- [ ]  If there is entrypoint that it is a script (e.g., ENTRYPOINT ["sh", "my_entrypoint.sh"], ENTRYPOINT ["bash", "my_entrypoint.sh"]), ensure it runs no program, only scripts are allowed, no programs to run in the background (e.g, ENTRYPOINT ['nginx & bash'] would be forbidden). - find in folder for ENTRYPOINT and verify

### Running-time tests

- [ ]  The installation should have finished at this point, if any crashes in the process, ther evaluation finishes as failed
- [ ]  Run docker ps and verify the three containers are running; try again in a couple of minutes to verify none has crashed or restarted for no reason
- [ ]  Run `docker volume ls` to verify the volumes have been properly created and are listed
- [ ]  Run `docker network ls` to verify that the network declared in docker-compose.yml has been created and is present
- [ ]  Run `docker network inspect <network_name>` to check that the three services are listed in the network details
- [ ]  Containers must restart automatically in case of a crash - Replace any container CMD instruction for “CMD ["sh", "-c", "exit 1"]”, the container should built as usual, but when `docker ps` this container will be looped into status “Restarting”.
- [ ]  In your WordPress database, there must be two users - one admin, other non-admin → run `docker exec -it wordpress wp user list`; administrator’s username must not contain ’admin’, ’Admin’, ’administrator’, or ’Administrator’ (e.g., admin, administrator, Administrator, admin-123, etc)
- [ ]  Local volumes will be available at `/home/<your_username>/data` folder of the host machine (the VM) →run the command `docker volume ls` to see the names of the volumes, then run `docker volume inspect <volume_name>` and verify that `/home/<your_username>/data` is present at `"device"`: field
- [ ]  Your domain name -pointing at localhost IP address- must be `<your_username>.42.fr`  →  check in browser
- [ ]  NGINX service must be the sole entry point into your infrastructure → run command `docker ps --format 'table {{.Names}}\t{{.Ports}}'`, only nginx should have 0.0.0.0 and :::, which mean port fowarding that allows entry point, if other container does have that, it considered failed. The output should be something similar to:
    
    NAMES       PORTS
    mariadb     3306/tcp
    nginx       0.0.0.0:443->443/tcp, :::443->443/tcp
    wordpress   9000/tcp
    
- [ ]  You website has to be accessible only via port 443 - Try to specify a different port like `<your_username>.42.fr:4242`, you should not be able to view the site “Unable to connect”
- [ ]  Your site must use TLSv1.2 or TLSv1.3 protocol - On browser navigation bar, click on the lock icon at the left side, you can view the certificate info there, check that it is one of those two
- [ ]  Ensure that WordPress website is properly installed and configured before the submission of the project (you shouldn't see the WordPress Installation page when opening the site, no matter if you do `make re`)
- [ ]  You should not be able to access the project website via hhtp://, when you try this the browser should either send an error or redirect to https://. In case you can see the website, verify the navigation bar and the address, as probably the second scenario happened (redirection)

### Testing you WordPress site

- [ ]  Without login or register, comment some post.
- [ ]  Access admin area, check that you can approve or delete comments.
- [ ]  Edit the website from admin panel. Verify on the website that the page has been updated with the changes → Try for example to change web elements colors or text
- [ ]  Login with the second user -not-admin- verify that it cannot edit website or approved/delete comments.

### Last thing…

- [ ]  *PERSISTENCE* - Reboot the virtual machine. Once it has restarted, launch docker compose again. Then, verify that everything is functional, and that both WordPress and MariaDB are configured. The changes you made previously to the WordPress website should still be here. If any of the above points is not correct, the evaluation process ends now.