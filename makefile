all: main.o run.o string_list.o input.o string_split.o
	gcc main.o run.o string_list.o input.o string_split.o
	rm *.o

test: execute.o
	gcc execute.o
	rm *.o

clean:
	rm *.o

main.o: run.h
	gcc -c main.c
run.o: string_list.h input.h string_split.h
	gcc -c run.c
string_list.o:
	gcc -c string_list.c
input.o: string_split.h
	gcc -c input.c
string_split.o:
	gcc -c string_split.c
execute.o:
	gcc -c execute.c
