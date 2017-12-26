CC=gcc
CFLAGS=-Wall


big_pro.o: big_program.c part1.h
	gcc -c big_program.c -o big_pro.o 

part1.o: part1.h part1.c
	gcc -c part1.c

chap4: part1.o big_pro.o
	gcc part1.o big_pro.o -o c4


encrypt.o: encrpyt.c encrypt.h
	gcc -c encrpyt.c -o encrypt.o

decrypt.o: decrypt.c decrypt.h
	gcc -c decrypt.c

message_hider.o: message_hider.c decrypt.h encrypt.h
	gcc -c message_hider.c -o message_hider.o 

msg_hider: message_hider.o encrypt.o decrypt.o
	gcc message_hider.o encrypt.o decrypt.o -o msg_hider

clean :
	rm -f big_program  big_program.o part1.o
