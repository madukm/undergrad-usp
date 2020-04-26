all: main.o listaAdj.o
	gcc main.o listaAdj.o -o programa

main.o: main.c
	gcc main.c -c
 
listaAdj.o: listaAdj.c
	gcc listaAdj.c -c

run:
	./programa

clean:
	rm -rf programa *.o

