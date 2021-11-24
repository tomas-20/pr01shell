all: main.o run.o input.o string_split.o
	gcc main.o run.o input.o string_split.o
	rm *.o

test: execute.o string_split.o
	gcc execute.o string_split.o
	rm *.o

clean:
	rm *.o

main.o: run.h
	gcc -c main.c
run.o: input.h string_split.h
	gcc -c run.c
input.o: string_split.h
	gcc -c input.c
string_split.o:
	gcc -c string_split.c
execute.o: string_split.h
	gcc -c execute.c
