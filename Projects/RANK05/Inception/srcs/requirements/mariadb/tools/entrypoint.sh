# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 12:59:19 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 12:59:40 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

run_command() {
    eval "$1"
}

echo "Starting MariaDB installation..."
run_command "service mariadb start"

config="
[client-server]
# Port or socket location where to connect
port = 3306
socket = /run/mysqld/mysqld.sock

# Import all .cnf files from configuration directory
!includedir /etc/mysql/conf.d/
!includedir /etc/mysql/mariadb.conf.d/

[mysqld]
port = 3306
bind-address = 0.0.0.0
"
echo "$config" > /etc/mysql/my.cnf

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
    run_command "
    mysql_secure_installation << EOF
    $MYSQL_ROOT_PASSWORD
    y
    n
    y
    y
    y
    y
    EOF
    "
    echo "MySQL secure installation completed."
fi

echo "MariaDB Starting Setup."

run_command "
mariadb <<EOF
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER '$MYSQL_ADMIN_USER'@'%' IDENTIFIED BY '$MYSQL_ADMIN_PASSWORD';
CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_ADMIN_USER'@'%';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
SELECT user, host FROM mysql.user;
FLUSH PRIVILEGES;
exit
EOF
"

echo "MariaDB setup completed."

echo "Stopping MariaDB..."
run_command "service mariadb stop"

echo "Starting MariaDB as a Server..."
run_command "exec mysqld --datadir=/var/lib/mysql"
