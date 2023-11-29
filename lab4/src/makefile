CC=gcc
CFLAGS=-I.

all: parallel_min_max procces_memory

parallel_min_max: find_min_max.o utils.o utils.h find_min_max.h
	$(CC) -o parallel_min_max find_min_max.o utils.o parallel_min_max.c $(CFLAGS)

procces_memory:
	$(CC) -o process_memory process_memory.c $(CFLAGS)

clean: 
	rm utils.o find_min_max.o parallel_min_max procces_memory