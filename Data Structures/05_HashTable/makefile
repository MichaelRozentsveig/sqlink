

CFLAGS  = -pedantic -g -Wall 

aprog : Hash.o HashTest.o

	gcc -o aprog Hash.o HashTest.o

a1.o : Hash.c Hash.h

	gcc -c $(CFLAGS) Hash.c

a2.o : HashTest.c Hash.h

	gcc -c $(CFLAGS) HashTest.c

