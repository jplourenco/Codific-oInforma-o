CC=gcc
CFLAGS=-g

all: compr decompr

lzrw1-a.o: lzrw1-a.c
	$(CC) $(CFLAGS) -c -o lzrw1-a.o lzrw1-a.c

compr: compr.c lzrw1-a.o
	$(CC) $(CFLAGS) -o compr compr.c lzrw1-a.o
decompr: decompr.c lzrw1-a.o
	$(CC) $(CFLAGS) -o decompr decompr.c lzrw1-a.o
clean:
	/bin/rm -rf compr decompr *.o


