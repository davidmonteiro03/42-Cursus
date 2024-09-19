# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 12:59:19 by dcaetano          #+#    #+#              #
#    Updated: 2024/09/19 13:14:56 by dcaetano         ###   ########.fr        #
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

if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then
    run_command "
    mysql_secure_installation << EOF
    $DB_ROOT
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
CREATE DATABASE IF NOT EXISTS $DB_NAME;
CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';
CREATE USER '$WP_USER'@'%' IDENTIFIED BY '$WP_PASS';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$WP_USER'@'%';
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
