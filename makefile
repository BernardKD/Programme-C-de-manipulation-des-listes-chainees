CC = gcc
CFLAGS = -Wall -Wextra
OBJECTS = main.o td112.o

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)

main.o: main.c td112.h
	$(CC) $(CFLAGS) -c main.c

td112.o: td112.c td112.h
	$(CC) $(CFLAGS) -c td112.c

clean:
	rm -f main $(OBJECTS)
