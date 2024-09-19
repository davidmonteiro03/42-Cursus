# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    entrypoint.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:38:51 by dcaetano          #+#    #+#              #
#    Updated: 2024/09/19 12:54:25 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

# Definir variáveis
WORDPRESS_URL="https://wordpress.org/latest.tar.gz"
WP_CLI_URL="https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar"
WORDPRESS_DIR="/var/www/html"
PHP_FPM_CONF="/etc/php/7.4/fpm/pool.d/www.conf"
TMP_CONF="/tmp/www.conf"

# Baixar e extrair WordPress
echo "Baixando WordPress..."
wget $WORDPRESS_URL -O latest.tar.gz
if [ $? -ne 0 ]; then
    echo "Erro ao baixar WordPress"
    exit 1
fi

echo "Extraindo WordPress..."
tar -xvf latest.tar.gz
rm -rf latest.tar.gz

# Mover arquivos do WordPress
echo "Movendo arquivos do WordPress..."
if [ -d "wordpress" ]; then
    mv wordpress/* $WORDPRESS_DIR
else
    echo "Diretório wordpress não encontrado"
    exit 1
fi

# Configurar permissões
echo "Configurando permissões..."
mkdir -p $WORDPRESS_DIR
chown -R www-data:www-data $WORDPRESS_DIR
chmod -R 777 $WORDPRESS_DIR

# Configurar PHP-FPM
echo "Configurando PHP-FPM..."
mkdir -p /run/php
chown -R www-data:www-data $WORDPRESS_DIR
if [ -f $TMP_CONF ]; then
    mv $TMP_CONF $PHP_FPM_CONF
else
    echo "Arquivo de configuração PHP-FPM não encontrado"
    exit 1
fi

# Baixar e configurar WP-CLI
echo "Baixando WP-CLI..."
wget $WP_CLI_URL -O wp-cli.phar
if [ $? -ne 0 ]; then
    echo "Erro ao baixar WP-CLI"
    exit 1
fi

chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

# Configurar WordPress
echo "Configurando WordPress..."
cd $WORDPRESS_DIR
cp wp-config-sample.php wp-config.php
sed -i "s/database_name_here/$DB_NAME/g" wp-config.php
sed -i "s/username_here/$DB_USER/g" wp-config.php
sed -i "s/password_here/$DB_PASS/g" wp-config.php
sed -i "s/localhost/$DB_HOST/g" wp-config.php

# Instalar WordPress
echo "Instalando WordPress..."
wp core install --url="https://$DOMAIN" \
    --title="$WP_TITLE" \
    --admin_user="$DB_USER" \
    --admin_password="$DB_PASS" \
    --admin_email="$DB_MAIL" \
    --skip-email \
    --path="$WORDPRESS_DIR" \
    --allow-root

# Criar usuário WordPress
echo "Criando usuário WordPress..."
wp user create $WP_USER $WP_MAIL \
    --role=author \
    --user_pass="$WP_PASS" \
    --path="$WORDPRESS_DIR" \
    --allow-root

# Iniciar PHP-FPM
echo "Iniciando PHP-FPM..."
/usr/sbin/php-fpm7.4 -F
