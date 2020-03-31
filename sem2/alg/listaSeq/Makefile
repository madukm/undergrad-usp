run: a
		./a

all: main.o lista.o
		gcc -g main.o lista.o -o a -Wall

main.o:
		gcc -g -c main.c

lista.o:
		gcc -g -c lista.c

clean:
		rm: *.o a
