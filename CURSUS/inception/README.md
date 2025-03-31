# Inception

This project is a system administration exercise focused on Docker containerization. The goal is to set up a small infrastructure with multiple services using Docker containers, following specific rules and best practices.

### Project Requirements

**Infrastructure Components**

- NGINX container with TLSv1.2 or TLSv1.3 only

- WordPress + PHP-FPM container (without NGINX)

- MariaDB container (without NGINX)

- Two volumes:
        - One for WordPress database
        - One for WordPress website files

- A Docker network to connect all containers

**Technical Specifications**

- Must be completed on a Virtual Machine

- All configuration files must be placed in a srcs folder

- Must include a Makefile at the root to build the entire application

- Containers must be built from either Alpine or Debian (penultimate stable version)

- Each service must have its own Dockerfile

- Forbidden to use pre-made images (except Alpine/Debian base images)

- Containers must restart automatically on crash

**Security Requirements**

- No passwords in Dockerfiles

- Must use environment variables

- Recommended to use .env file and Docker secrets

- WordPress admin username must not contain variations of "admin"

- NGINX must be the sole entry point (port 443 only)

- Domain name must be login.42.fr (replace "login" with your actual login)

### Directory Structure
```text
.
├── Makefile
├── secrets/
│   ├── credentials.txt
│   ├── db_password.txt
│   ├── db_root_password.txt
└── srcs/
    ├── docker-compose.yml
    ├── .env
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   └── tools/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            ├── .dockerignore
            ├── conf/
            └── tools/
```
### Setup Instructions

1. Prerequisites:

- Virtual Machine

- Docker and Docker Compose installed

2. Configuration:

- Update the .env file with your specific variables

- Place all secrets in the secrets directory

- Configure your domain name (login.42.fr) to point to your local IP

3. Building and Running:

- Run make at the root directory to build and start all containers

- The Makefile will use docker-compose.yml to build and run the containers

4. Access:

- Access your WordPress site via HTTPS at https://login.42.fr

### Important Notes

- Do not use network: host or --link

- Do not use infinite loop commands (tail -f, bash, sleep infinity, etc.)

- The latest tag is prohibited

- All containers must be properly daemonized

- Follow Docker best practices for PID 1

### Security Reminder

All credentials, API keys, and passwords must be stored securely and never committed to version control. Use the provided secrets mechanism and .env file for configuration.

This implementation covers only the mandatory part of the project as specified in the subject.