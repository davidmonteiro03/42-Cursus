all:
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d --build

fclean:
	@sudo docker-compose -f ./srcs/docker-compose.yml down
	@sudo docker-compose -f ./srcs/docker-compose.yml rm -f
	@sudo docker-compose -f ./srcs/docker-compose.yml rmi -f

.PHONY: all fclean
