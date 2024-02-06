FROM debian:bullseye

RUN apt-get update
RUN apt-get install -y nginx

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]
