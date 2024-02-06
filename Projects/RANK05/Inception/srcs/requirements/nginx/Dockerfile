FROM debian:bullseye

RUN apt-get update
RUN apt-get install -y nginx openssl

COPY ./tools/script.sh /

RUN chmod +x /script.sh

CMD ["/script.sh"]
