CC=gcc
CFLAGS=-Wall


big_pro.o: big_program.c part1.h
	gcc -c big_program.c -o big_pro.o 

part1.o: part1.h part1.c
	gcc -c part1.c

chap4: part1.o big_pro.o
	gcc part1.o big_pro.o -o c4

clean :
	rm -f big_program  big_program.o part1.o
