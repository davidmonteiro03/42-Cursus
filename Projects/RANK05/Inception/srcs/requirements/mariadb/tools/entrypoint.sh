# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 13:11:43 by dcaetano          #+#    #+#              #
#    Updated: 2024/09/19 13:12:05 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

echo "Starting MariaDB installation..."
service mariadb start

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

if [ -w /etc/mysql/my.cnf ]; then
    echo "$config" > /etc/mysql/my.cnf
else
    echo "Warning: /etc/mysql/my.cnf cannot be written."
fi

if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then
    mysql_secure_installation << EOF
$DB_ROOT
y
n
y
y
y
y
EOF
    echo "MySQL secure installation completed."
fi

echo "MariaDB Starting Setup."

mariadb <<EOF
CREATE DATABASE IF NOT EXISTS $DB_NAME;
CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';
CREATE USER IF NOT EXISTS '$WP_USER'@'%' IDENTIFIED BY '$WP_PASS';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$WP_USER'@'%';
SELECT user, host FROM mysql.user;
FLUSH PRIVILEGES;
exit
EOF

echo "MariaDB setup completed."

echo "Stopping MariaDB..."
if pgrep mariadbd > /dev/null; then
    service mariadb stop
else
    echo "MariaDB is not running."
fi

echo "Starting MariaDB as a Server..."
exec mysqld --datadir=/var/lib/mysql
