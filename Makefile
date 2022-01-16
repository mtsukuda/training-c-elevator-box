CC= cc
CFLAGS= -std=c99 -pedantic -Wall
OBJECTS= eb.o
all: eb
eb.o: eb.c
	$(CC) $(CFLAGS) -c eb.c
eb: $(OBJECTS)
	$(CC) $(OBJECTS) -o eb
clean:
	rm -f *.o eb
