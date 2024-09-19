# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:38:51 by dcaetano          #+#    #+#              #
#    Updated: 2024/09/19 12:59:52 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

# Define variables
WORDPRESS_URL="https://wordpress.org/latest.tar.gz"
WP_CLI_URL="https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar"
WORDPRESS_DIR="/var/www/html"
PHP_FPM_CONF="/etc/php/7.4/fpm/pool.d/www.conf"
TMP_CONF="/tmp/www.conf"

# Download and extract WordPress
echo "Downloadind WordPress..."
wget $WORDPRESS_URL -O latest.tar.gz
if [ $? -ne 0 ]; then
    echo "Error downloading WordPress"
    exit 1
fi

echo "Extracting WordPress..."
tar -xvf latest.tar.gz
rm -rf latest.tar.gz

# Move WordPress files
echo "Moving WordPress files..."
if [ -d "wordpress" ]; then
    mv wordpress/* $WORDPRESS_DIR
else
    echo "Wordpress directory not found"
    exit 1
fi

# Setup permissions
echo "Setting up permitions..."
mkdir -p $WORDPRESS_DIR
chown -R www-data:www-data $WORDPRESS_DIR
chmod -R 777 $WORDPRESS_DIR

# Setup PHP-FPM
echo "Setting up PHP-FPM..."
mkdir -p /run/php
chown -R www-data:www-data $WORDPRESS_DIR
if [ -f $TMP_CONF ]; then
    mv $TMP_CONF $PHP_FPM_CONF
else
    echo "PHP-FPM configuration file not found"
    exit 1
fi

# Download e setup WP-CLI
echo "Downloading WP-CLI..."
wget $WP_CLI_URL -O wp-cli.phar
if [ $? -ne 0 ]; then
    echo "Error downloading WP-CLI"
    exit 1
fi

chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

# Setup WordPress
echo "Setting up WordPress..."
cd $WORDPRESS_DIR
cp wp-config-sample.php wp-config.php
sed -i "s/database_name_here/$DB_NAME/g" wp-config.php
sed -i "s/username_here/$DB_USER/g" wp-config.php
sed -i "s/password_here/$DB_PASS/g" wp-config.php
sed -i "s/localhost/$DB_HOST/g" wp-config.php

# Install WordPress
echo "Installing WordPress..."
wp core install --url="https://$DOMAIN" \
    --title="$WP_TITLE" \
    --admin_user="$DB_USER" \
    --admin_password="$DB_PASS" \
    --admin_email="$DB_MAIL" \
    --skip-email \
    --path="$WORDPRESS_DIR" \
    --allow-root

# Create WordPress user
echo "Creating WordPress user..."
wp user create $WP_USER $WP_MAIL \
    --role=author \
    --user_pass="$WP_PASS" \
    --path="$WORDPRESS_DIR" \
    --allow-root

# Start PHP-FPM
echo "Starting PHP-FPM..."
/usr/sbin/php-fpm7.4 -F
