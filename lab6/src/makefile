CC=gcc
CFLAGS=-I.

all: client server

server: multmodulo.o multmodulo.h
	$(CC) -o server multmodulo.o server.c -lpthread


client: multmodulo.o multmodulo.h
	$(CC) -o client multmodulo.o client.c -lpthread

clean:
	rm client client.o server server.o multmodulo.o