FROM debian:latest

WORKDIR /app

RUN apt-get update && \
	apt-get install -y gcc libc6-dev

CMD ["cc", "-v"]
