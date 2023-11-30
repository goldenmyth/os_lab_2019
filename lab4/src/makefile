CC=gcc
CFLAGS=-I.

all: parallel_min_max parallel_sum process_memory

parallel_min_max: find_min_max.o utils.o utils.h find_min_max.h
	$(CC) -o parallel_min_max find_min_max.o utils.o parallel_min_max.c $(CFLAGS)

process_memory:
	$(CC) -o process_memory process_memory.c $(CFLAGS)

parallel_sum: sum.o utils.o sum.h utils.h
	$(CC) -o parallel_sum sum.o utils.o parallel_sum.c -lpthread

clean: 
	rm utils.o find_min_max.o sum.o parallel_min_max parallel_sum process_memory