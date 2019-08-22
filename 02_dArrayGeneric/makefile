

CFLAGS  = -pedantic -g -Wall 

aprog : darray_generic.o darray_Test.o

	gcc -o aprog darray_generic.o darray_Test.o

a1.o : darray_generic.c darray_generic.h

	gcc -c $(CFLAGS) darray_generic.c

a2.o : darrayTest.c darray_generic.h

	gcc -c $(CFLAGS) darray_Test.c

