# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:38:51 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 14:06:20 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm -rf latest.tar.gz
mv wordpress /var/www/html
cd /var/www/html/wordpress
mv /tmp/wp-config.php /var/www/html/wordpress
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 777 /var/www/html/wordpress
mkdir -p /run/php
chown -R www-data:www-data /var/www/html/wordpress
wp core download --allow-root
wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_ADMIN_USER --dbpass=$MYSQL_ADMIN_PASSWORD --dbhost="mariadb" --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
wp core install --url=$DOMAIN/wordpress --title=$WP_TITLE --admin_user=$MYSQL_ADMIN_USER --admin_password=$MYSQL_ADMIN_PASSWORD --admin_email=$MYSQL_ADMIN_EMAIL --skip-email --allow-root
wp user create $MYSQL_USER $MYSQL_USER_EMAIL --role=author --user_pass=$MYSQL_PASSWORD --allow-root
wp theme install inspiro --activate --allow-root
/usr/sbin/php-fpm7.4 -F
