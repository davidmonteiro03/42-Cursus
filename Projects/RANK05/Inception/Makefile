all:
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d --build

down:
	@sudo docker-compose -f ./srcs/docker-compose.yml down

re: down all

clean:
	@sudo docker stop $$(docker ps -qa) || true
	@sudo docker rm $$(docker ps -qa) || true
	@sudo docker rmi -f $$(docker images -qa) || true
	@sudo docker volume rm $$(docker volume ls -q) || true
	@sudo docker network rm $$(docker network ls -q) || true

.PHONY: all re down clean
