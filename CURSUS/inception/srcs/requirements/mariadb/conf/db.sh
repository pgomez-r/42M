#!/bin/sh

# Check if MySQL system database exists
if [ ! -d "/var/lib/mysql/mysql" ]; then

	echo "Initializing MariaDB data directory..."
	chown -R mysql:mysql /var/lib/mysql

	# Init the database
	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm
	if [ $? -ne 0 ]; then
		echo "Error: Failed to initialize MariaDB data directory."
		exit 1
	fi

	tfile=$(mktemp)
	if [ ! -f "$tfile" ]; then
		echo "Error: Failed to create temp file."
		exit 1
	fi
fi

# Check if the WordPress database exists
if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then
	echo "Creating database and user..."

	cat << EOF > /tmp/create_db.sql
USE mysql;
FLUSH PRIVILEGES;

DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test';

DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT}';

CREATE DATABASE ${DB_NAME} CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASS}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

	# Run the SQL script to set up the database
	/usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db.sql
	if [ $? -ne 0 ]; then
		echo "Error: Failed to create database and user."
		exit 1
	fi
	rm -f /tmp/create_db.sql
fi
