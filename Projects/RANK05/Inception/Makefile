all:
	@sudo docker compose -f ./scrs/docker-compose.yml up -d --build

down:
	@sudo docker compose -f ./scrs/docker-compose.yml down

re:
	@sudo docker compose -f scrs/docker-compose.yml up -d --build

clean:
	@sudo docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\

.PHONY: all re down clean
