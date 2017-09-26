
CC          =	gcc
# Flags that are sent to the compiler  change the std if you wish

CFLAGS      =	-Wall -std=c99 -g


all:
	$(CC) $(CFLAGS) src/*.c -Iinclude -o bin/runMe


clean:
	rm bin/*