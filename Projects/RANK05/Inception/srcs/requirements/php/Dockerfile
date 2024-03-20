# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 09:16:48 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/20 09:35:42 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base image
FROM debian:bullseye

# Update and upgrade packages
RUN apt-get update -y
RUN apt-get upgrade -y

# Install PHP and its extensions
RUN apt-get install -y php php-fpm php-mysql php-mbstring php-xml php-gd php-curl

WORKDIR /var/www/html

# Config PHP
COPY ./tools/php-config.sh /tmp/php-config.sh
CMD ["sh", "/tmp/php-config.sh"]
