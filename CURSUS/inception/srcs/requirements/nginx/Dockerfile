# OS Base image
FROM debian:bullseye

# Install dependencies and create nginx ssl folder to store certificates later
# procps is installed to use the command "ps" and "kill" for debugging
RUN apt-get update && apt-get install -y nginx openssl procps && mkdir -p /etc/nginx/ssl

# Generate ssl certificate and key
RUN openssl req -subj "/C=SP/ST=Malaga/L=Malaga/O=42 Malaga/OU=pgomez-r/CN=pgomez-r" \
    -new -newkey rsa:2048 -days 365 -nodes -x509 \
    -keyout /etc/nginx/ssl/pgomez-r.42.fr.key -out /etc/nginx/ssl/pgomez-r.42.fr.crt

# Copy our nginx configuration file to the default location
COPY conf/nginx.conf /etc/nginx/sites-available/default

# Expose port 443 for https, this is only informational, expose does not publish the port
EXPOSE 443

# CMD to be executed when docker-compose, to run nginx without daemon "mode"
CMD ["nginx", "-g", "daemon off;"]

# CMD to force crash - to check that containers restart on-failure
# CMD ["sh", "-c", "exit 1"]