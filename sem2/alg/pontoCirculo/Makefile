run: a
		./a

all: main.o ponto.o circulo.o
		gcc -g main.o circulo.o ponto.o -o a -Wall -lm

main.o:
		gcc -g -c main.c

circulo.o: ponto.o
		gcc -g -c circulo.c

ponto.o:
		gcc -g -c ponto.c

clean:
		rm: *.o a
