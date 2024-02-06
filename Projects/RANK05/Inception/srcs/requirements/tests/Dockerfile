FROM debian:bullseye

RUN apt-get update && apt-get install -y gcc
RUN create_main.sh
RUN cc -Wall -Wextra -Werror main.c -o main
RUN main
