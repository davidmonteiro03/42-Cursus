FROM debian:bullseye

COPY main.c .

RUN apt-get update && apt-get install -y gcc

CMD ["cc", "main.c", "&&", "./a.out"]
