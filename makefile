all: test.o run.o input.o
	gcc test.o run.o input.o
	rm *.o
test.o: run.h
	gcc -c test.c
run.o: input.h
	gcc -c run.c
input.o:
	gcc -c input.c
