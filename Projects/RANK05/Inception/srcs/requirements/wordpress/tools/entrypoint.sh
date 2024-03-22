# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:38:51 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 17:24:26 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm -rf latest.tar.gz
mv wordpress /var/www/html
mkdir -p /var/www/html/wordpress
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 777 /var/www/html/wordpress
mkdir -p /run/php
chown -R www-data:www-data /var/www/html/wordpress
mv /tmp/www.conf /etc/php/7.4/fpm/pool.d/www.conf
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/html/wordpress
cp wp-config-sample.php wp-config.php
sed -i "s/database_name_here/$DB_NAME/g" wp-config.php
sed -i "s/username_here/$DB_USER/g" wp-config.php
sed -i "s/password_here/$DB_PASS/g" wp-config.php
sed -i "s/localhost/$DB_HOST/g" wp-config.php
wp core install --url="https://$DOMAIN/wordpress" \
	--title=$WP_TITLE \
	--admin_user=$DB_USER \
	--admin_password=$DB_PASS \
	--admin_email=$DB_MAIL \
	--skip-email \
	--path="/var/www/html/wordpress" \
	--allow-root
wp user create $WP_USER $WP_MAIL \
	--role=author \
	--user_pass=$WP_PASS \
	--path="/var/www/html/wordpress" \
	--allow-root
/usr/sbin/php-fpm7.4 -F
