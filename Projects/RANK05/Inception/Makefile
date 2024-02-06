.PHONY: all build test clean

all: build

build:
	@docker-compose build

test:
	@docker-compose run --rm tests

clean:
	@docker-compose down -v --remove-orphans
