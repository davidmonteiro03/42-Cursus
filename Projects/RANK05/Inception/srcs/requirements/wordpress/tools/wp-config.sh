#!/bin/sh
mkdir -p /run/php/
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/* /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress
rm -rf latest.tar.gz
/usr/sbin/php-fpm7.4 -F
exit 0
