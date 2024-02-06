all: build run

build:
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d --build

run:
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d

.PHONY: all fclean
