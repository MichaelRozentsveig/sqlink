

CFLAGS  = -pedantic -g -Wall 

aprog : BST.o TestBST.o

	gcc -o aprog BST.o TestBST.o

a1.o : BST.c BST.h

	gcc -c $(CFLAGS) BST.c

a2.o : TestBST.c BST.h

	gcc -c $(CFLAGS) TestBST.c

