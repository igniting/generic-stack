CC = gcc
CFLAGS = -g -Wall

stacktest: stacktest.o stack.o
	$(CC) $(CFLAGS) -o stacktest stacktest.o stack.o

stacktest.o: stacktest.c stack.h
	$(CC) $(CFLAGS) -c stacktest.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

run: stacktest
	./stacktest

clean:
	rm -f *.o *.gch stacktest
