# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 14:32:28 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 11:24:12 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/$DOMAIN.key \
	-out /etc/ssl/certs/$DOMAIN.crt \
	-subj "/C=PT/ST=Porto/L=Porto/O=42/CN=$DOMAIN"

echo "
server {
	listen 443 ssl;
	listen [::]:443 ssl;

	server_name $DOMAIN www.$DOMAIN;

	ssl_certificate /etc/ssl/certs/$DOMAIN.crt;
	ssl_certificate_key /etc/ssl/private/$DOMAIN.key;
	ssl_protocols TLSv1.2 TLSv1.3;

	root /var/www/html;
	index index.php index.html index.htm index.nginx-debian.html;

	location / {
		try_files \$uri \$uri/ /index.php\$is_args\$args;
	}

	location ~ \.php$ {
		fastcgi_pass wordpress:9000;
		fastcgi_index index.php;
		fastcgi_param SCRIPT_FILENAME \$document_root\$fastcgi_script_name;
		include fastcgi_params;
	}
}" > /etc/nginx/conf.d/default.conf

/usr/sbin/nginx -g "daemon off;"
