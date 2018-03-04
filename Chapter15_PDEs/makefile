CFLAGS = -Wall -O
CC = gcc
NRC=/home/norbert/Research/Nrc/


advect:	advect.c gaussj.o nrutil.o makefile
	$(CC) $(CFAGS) advect.c gaussj.o nrutil.o -lm

gaussj.o: $(NRC)gaussj.c makefile
	$(CC) -c -O $(NRC)gaussj.c

nrutil.o: $(NRC)nrutil.c makefile
	$(CC) -c -O $(NRC)nrutil.c

clean:
	rm -f *.out *.o

