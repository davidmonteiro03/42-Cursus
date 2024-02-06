all:
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d --build

fclean:
	@sudo docker-compose -f ./srcs/docker-compose.yml down
	@sudo docker-compose -f ./srcs/docker-compose.yml rm -f
	@sudo docker-compose -f ./srcs/docker-compose.yml rmi -f
	@sudo docker volume rm $$(sudo docker volume ls -q) || true
	@sudo docker network rm $$(sudo docker network ls -q) || true

.PHONY: all fclean
