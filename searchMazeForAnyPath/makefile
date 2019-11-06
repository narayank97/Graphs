CFLAGS = -O
CC = g++
output: main.o coordinate.o
	$(CC) $(CFLAGS) -o output main.o coordinate.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
coordinate.o: coordinate.cpp
	$(CC) $(CFLAGS) -c coordinate.cpp
clean:
	rm -f core *.o 