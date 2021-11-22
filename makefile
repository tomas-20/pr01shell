all: test.o run.o string_list.o input.o string_split.o
	gcc test.o run.o string_list.o input.o string_split.o
	rm *.o
test.o: run.h
	gcc -c test.c
run.o: string_list.h input.h string_split.h
	gcc -c run.c
string_list.o:
	gcc -c string_list.c
input.o: string_split.h
	gcc -c input.c
string_split.o:
	gcc -c string_split.c
