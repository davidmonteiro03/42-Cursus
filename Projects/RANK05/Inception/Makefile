IMAGE_NAME := myapp

CONTAINER_NAME := myapp-container

all: build run

build:
	@sudo docker build -t $(IMAGE_NAME) .

run:
	@sudo docker run --rm --name $(CONTAINER_NAME) $(IMAGE_NAME)
