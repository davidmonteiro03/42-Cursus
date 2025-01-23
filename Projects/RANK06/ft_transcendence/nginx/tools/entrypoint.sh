#!/bin/bash
# SSL Certificate

certs_dir="/etc/ssl/certs"
cert_file="$certs_dir/$HOSTNAME.crt"
key_file="$certs_dir/$HOSTNAME.key"
config_file="$certs_dir/openssl.cnf"

if [ ! -f "$cert_file" ] || [ ! -f "$key_file" ]; then
    cat <<EOF > $config_file
[req]
distinguished_name = req_distinguished_name
req_extensions = req_ext
x509_extensions = v3_ca
prompt = no

[req_distinguished_name]
C = PT
ST = Porto
L = Porto
O = 42Porto
CN = $HOSTNAME

[req_ext]
subjectAltName = @alt_names

[v3_ca]
subjectAltName = @alt_names

[alt_names]
DNS.1 = $HOSTNAME
EOF

    openssl req -new -newkey rsa:2048 -days 365 -nodes -x509 \
        -keyout $key_file \
        -out $cert_file \
        -config $config_file
    openssl x509 -in $cert_file -text -noout
    openssl rsa -in $key_file -check
fi

cat << eof > /etc/nginx/conf.d/default.conf
server {
    listen $DJANGO_PORT ssl;
    listen [::]:$DJANGO_PORT ssl;

    server_name $HOSTNAME;

    ssl_certificate $cert_file;
    ssl_certificate_key $key_file;
    ssl_protocols TLSv1.2 TLSv1.3;

    location / {
        proxy_pass http://transcendence:$DJANGO_PORT;
        proxy_set_header Host \$host;
        proxy_set_header X-Real-IP \$remote_addr;
        proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto \$scheme;
        proxy_set_header X-Forwarded-Host \$host;
        proxy_set_header X-Forwarded-Port \$server_port;
    }

    location /ws/ {
        proxy_pass http://transcendence:$DJANGO_PORT;
        proxy_http_version 1.1;
        proxy_set_header Upgrade \$http_upgrade;
        proxy_set_header Connection "Upgrade";
        proxy_set_header Host \$host;
    }

    location /favicon.ico {
        alias /transcendence/staticfiles/favicon.ico;
    }

    location /static/ {
        alias /transcendence/staticfiles/;
    }

    location /media/ {
        alias /transcendence/media/;
    }
}
eof

nginx -g "daemon off;"
