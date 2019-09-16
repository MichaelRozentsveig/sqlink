

CFLAGS  = -pedantic -g -Wall  -lm -lrt -pthread

aprog : proCon.o proConTest.o

	gcc -pthread -o aprog proCon.o proConTest.o

proCon.o : proCon.c proCon.h

	gcc  -c $(CFLAGS) proCon.c 

proConTest.o : proConTest.c proCon.h

	gcc  -c $(CFLAGS) proConTest.c 

