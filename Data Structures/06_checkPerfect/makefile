

CFLAGS  = -pedantic -g -Wall 

aprog : perTree.o TreeTest.o

	gcc -o aprog perTree.o TreeTest.o

a1.o : perTree.c perTree.h

	gcc -c $(CFLAGS) perTree.c

a2.o : TreeTest.c perTree.h

	gcc -c $(CFLAGS) TreeTest.c

