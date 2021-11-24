all: run.o input.o string_split.o
	gcc run.o input.o string_split.o
	rm *.o

clean:
	rm *.o

run.o: input.h
	gcc -c run.c
input.o: string_split.h
	gcc -c input.c
string_split.o:
	gcc -c string_split.c
