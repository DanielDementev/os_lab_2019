CC=gcc
CFLAGS=-I.



sequential_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o sequential_min_max find_min_max.o utils.o sequential_min_max.c $(CFLAGS)

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

process_memory : process_memory.o
	$(CC) -o process_memory.o process_memory.c $(CFLAGS)

exec_seq: sequential_min_max
	./sequential_min_max 1 100

parallel_sum: utils.h utils.o sum.o sum.h
	$(CC) -o parallel_sum sum.o utils.o parallel_sum.c -lpthread

sum.o: sum.h
	$(CC) -o sum.o -c sum.c

clean :
	rm  parallel_min_max process_memory
