# Inception Guide

This guide has been made using as its base a translation of the guide by codesshaman at https://github.com/codesshaman/inception/tree/main?tab=readme-ov-file. 

My first intention was just to translate, follow and revise the guide, but as I was developing the project -and finding challanges along with it, as usual- I chose to do several things differently, so this has ended up being an adaptation into my own guide, more than just a translation.

However, I am aware that it is far from being perfect. I have tried to keep it updated with all changes that I needed to do in my code simultaneously as I was developing the project, still there could be some mistakes or missing points. Sorry about that and also about some spelling or grammar mistakes **-is there any extension in VSCode to check those?...-.**

For any suggestions or help, I'd be happy to hear!

## Project steps

> The idea of this guide is to first set our working environment, which will consist of installing and setting the VM with all necessary packages and configurations; then we will move to Docker basic concept and will set each container but on its own, and the last stage will be -once each container is working properly by itself- to connect all of them and finish all configurations and subject requirements.

Brief info about the stages of the project:

- [x] Installing the OS in virtualbox - [guide 00](https://github.com/pgomez-r/inception/tree/main/guide/00_INSTALL_SYSTEM.md "Installing the OS in virtualbox")
- [x] Installing software inside the OS - [guide 01](https://github.com/pgomez-r/inception/tree/main/guide/01_INSTALL_SOFT.md "Installing software inside the OS")
- [x] Port forwarding to the host - [guide 02](https://github.com/pgomez-r/inception/tree/main/guide/02_PORTS_FORWARDING.md "Forwarding ports to the host")
- [x] Saving snapshots to the cloud - [guide 03](https://github.com/pgomez-r/inception/tree/main/guide/03_CLOUD_STORAGE.md "Saving snapshots to the cloud")
- [x] Pre-setup - [guide 04](https://github.com/pgomez-r/inception/tree/main/guide/04_FIRST_SETTINGS.md "Pre-setup")
- [x] Certificate Installation - [guide 05](https://github.com/pgomez-r/inception/tree/main/guide/05_INSTALL_CERTIFICATE.md "Installing the certificate")
- [x] Creating a Makefile - [guide 06](https://github.com/pgomez-r/inception/tree/main/guide/06_MAKEFILE_CREATION.md "Creating a Makefile")
- [x] Docker basics - [guide 07](https://github.com/pgomez-r/inception/tree/main/guide/07_DOCKER_BASICS.md "Docker basic concepts")
- [x] NGINX service - [guide 08](https://github.com/pgomez-r/inception/tree/main/guide/08_DOCKER_NGINX.md "nginx Deployment")
- [x] MariaDB service - [guide 09](https://github.com/pgomez-r/inception/tree/main/guide/09_DOCKER_MARIADB.md "mariadb Deployment")
- [x] Wordpress service - [guide 10](https://github.com/pgomez-r/inception/tree/main/guide/10_DOCKER_WORDPRESS.md "Wordpress Deployment")
- [x] Connect all services together - [guide 11](https://github.com/pgomez-r/inception/tree/main/guide/11_LINK_SERVICES.md "Link Services")
- [x] Getting ready for evaluation - [guide 12](https://github.com/pgomez-r/inception/tree/main/guide/12_EVALUATION_CHECKS.md "Evaluation")

***BONUS PART***
**(!) This is just an automatic translation of the original guide - Has not been revised or improved in any way (!)**
- [ ] Redis Installation - [guide Bonus 01](https://github.com/pgomez-r/inception/tree/main/guide/B1_WORDPRESS_REDIS.md "Installing Redis")
- [ ] Installing vsftpd - [guide Bonus 02](https://github.com/pgomez-r/inception/tree/main/guide/B2_VSFTPD_SERVER.md "Installing vsftpd")
- [ ] Installing Adminler - [guide Bonus 03](https://github.com/pgomez-r/inception/tree/main/guide/B3_INSTALL_ADMINER.md "Install Adminler")
- [ ] Install portainer - guide [guide Bonus 04](https://github.com/pgomez-r/inception/tree/main/guide/B4_PORTAINER_INSTALL.md "Installing the portainer")

For a deeper understanding of Docker:
https://ivan-shamaev.ru/docker-compose-tutorial-container-image-install/
