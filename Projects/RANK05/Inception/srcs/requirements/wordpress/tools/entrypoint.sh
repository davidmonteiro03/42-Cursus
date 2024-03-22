# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:38:51 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 08:19:26 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm -rf latest.tar.gz
rm -rf /var/www/html/*
mv wordpress /var/www/html/

/usr/sbin/php-fpm7.4 -F
