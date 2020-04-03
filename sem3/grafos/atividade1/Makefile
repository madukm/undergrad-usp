all: main.o matrizAdj.o
		gcc main.o matrizAdj.o -o programa

main.o: main.c
		gcc main.c -c

matrizAdj.o: matrizAdj.c
		gcc matrizAdj.c -c

run:
		./programa


clean:
		rm -rf programa *.o
