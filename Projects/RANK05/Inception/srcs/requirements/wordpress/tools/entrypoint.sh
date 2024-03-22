# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:38:51 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 11:23:31 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm -rf latest.tar.gz
mv wordpress /var/www/html
mkdir -p /var/www/html/wordpress
chown -R www-data:www-data /var/www/html/worpress
chmod -R 777 /var/www/html/wordpress
mkdir -p /run/php
cd /var/www/html/wordpress
cp wp-config-sample.php wp-config.php
mv wp-config-sample.php /var/www/html/wordpress/wp-config.php
sed -i "s/username_here/$MYSQL_USERNAME/g" /var/www/html/wordpress/wp-config.php
sed -i "s/password_here/$MYSQL_PASSWORD/g" /var/www/html/wordpress/wp-config.php
sed -i "s/database_name_here/$MYSQL_DATABASE/g" /var/www/html/wordpress/wp-config.php
sed -i "s/localhost/$MYSQL_HOST/g" /var/www/html/wordpress/wp-config.php
chown -R www-data:www-data /var/www/html/wordpress
/usr/sbin/php-fpm7.4 -F
