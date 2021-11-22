all: test.o run.o input.o string_list.o
	gcc test.o run.o input.o string_list.o
	rm *.o
test.o: run.h
	gcc -c test.c
run.o: input.h string_list.h
	gcc -c run.c
input.o:
	gcc -c input.c
string_list.o:
	gcc -c string_list.c
