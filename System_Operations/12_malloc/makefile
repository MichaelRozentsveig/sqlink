

CFLAGS  = -pedantic -g -Wall 

aprog : malloc.o mallocTest.o

	gcc -o aprog malloc.o mallocTest.o

malloc.o : malloc.c malloc.h

	gcc -c $(CFLAGS) malloc.c

mallocTest.o : mallocTest.c malloc.h

	gcc -c $(CFLAGS) mallocTest.c

