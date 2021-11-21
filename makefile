all: test.o input.o
	gcc test.o input.o
	rm *.o
test.o: input.h
	gcc -c test.c
input.o:
	gcc -c input.c
