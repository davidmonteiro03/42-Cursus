FROM debian:bullseye

RUN sudo apt-get install -y clang

RUN echo #include <stdio.h>\
int main(void)\
{\
	printf("Hello world!\n");\
	return (0);\
} > main.c

CMD ["cc", "-o", "main", "main.c", "&&", "./main"]
