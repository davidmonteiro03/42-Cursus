all: up

up:
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d

down:
	@sudo docker-compose -f ./srcs/docker-compose.yml down

stop:
	@sudo docker-compose -f ./srcs/docker-compose.yml stop

start:
	@sudo docker-compose -f ./srcs/docker-compose.yml start

status :
	@sudo docker ps
