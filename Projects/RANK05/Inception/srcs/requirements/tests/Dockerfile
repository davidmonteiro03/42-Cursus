FROM debian:bullseye

RUN apt-get update && apt-get install -y gcc
RUN cat <<eof > main.c
#include <stdio.h>

int	main(void)
{
	printf("Hello world!\n");
	return (0);
}
eof
