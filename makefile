all: process1.o process2.o
	gcc -o mainproc process1.o
	gcc -o sideproc process2.o

process1.o: process1.c
	gcc -c process1.c

process2.o: process2.c
	gcc -c process2.c
