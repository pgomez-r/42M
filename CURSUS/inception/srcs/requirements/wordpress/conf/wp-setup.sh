#!/bin/sh

# =============================================
# Early Exit Check - If WordPress is fully configured
# =============================================
if [ -f /var/www/html/wp-config.php ] && 
   wp core is-installed --allow-root --path="/var/www/html" && 
   wp user get "$WP_USER" --allow-root --path="/var/www/html" &>/dev/null; then
    echo "WordPress is already fully configured. Exiting setup."
    exit 0
fi

# =============================================
# Normal Setup Process (Only runs if not configured)
# =============================================

# Verify WP-CLI is installed
if ! command -v wp > /dev/null 2>&1; then
    echo "Error: WP-CLI (wp command) is not installed"
    exit 1
fi

# Verify WordPress files exist
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Error: WordPress files not found in /var/www/html"
    exit 1
fi

# Check if PHP is installed
if ! command -v php > /dev/null 2>&1; then
    echo "PHP is not installed. Exiting."
    exit 1
fi

echo "Creating setup with the following values:"
echo "DB_NAME: ${DB_NAME}"
echo "DB_USER: ${DB_USER}"
echo "DB_PASS: ${DB_PASS}"

# Wait for MariaDB to be ready
MAX_RETRIES=5
RETRY_COUNT=0
until mysql -h mariadb -u"${DB_USER}" -p"${DB_PASS}" -e "USE ${DB_NAME};" 2>/dev/null; do
    RETRY_COUNT=$((RETRY_COUNT+1))
    if [ $RETRY_COUNT -ge $MAX_RETRIES ]; then
        echo "Error: Could not connect to MariaDB after $MAX_RETRIES attempts"
        echo "Trying command: mysql -h mariadb -u${DB_USER} -p[hidden] -e \"USE ${DB_NAME};\""
        mysql -h mariadb -u"${DB_USER}" -p"${DB_PASS}" -e "USE ${DB_NAME};"
        exit 1
    fi
    echo "Waiting for MariaDB... (attempt $RETRY_COUNT/$MAX_RETRIES)"
    sleep 5
done

echo "Database ready. Proceeding with WordPress setup..."

# Only run core install if WordPress isn't already installed
if ! wp core is-installed --allow-root --path="/var/www/html"; then
    echo "Running WordPress core installation..."
    wp core install --allow-root \
        --url="https://$DOMAIN_NAME" \
        --title="pgomez-r inception" \
        --admin_user="$DB_USER" \
        --admin_password="$DB_PASS" \
        --admin_email="pedrogruz.11@gmail.com" \
        --path="/var/www/html"
    if [ $? -ne 0 ]; then
        echo "Error: wp core install failed."
        exit 1
    fi
else
    echo "WordPress is already installed. Skipping core installation."
fi

# Only create user if it doesn't exist
if ! wp user list --allow-root --path="/var/www/html" | grep -q "^\s*[0-9]\+\s\+$WP_USER\s"; then
    echo "Creating WordPress user '$WP_USER'..."
    wp user create "$WP_USER" "guest@example.com" \
        --role=author \
        --user_pass="$WP_PASS" \
        --allow-root \
        --path="/var/www/html"
    [ $? -ne 0 ] && echo "Error: Failed to create user" && exit 1
else
    echo "User '$WP_USER' already exists. Skipping creation."
fi

echo "WordPress setup completed successfully."
