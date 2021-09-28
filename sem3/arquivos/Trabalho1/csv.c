#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "csv.h"


char *read_field(FILE *file, int size){
	char *string;
	string = (char *)malloc((size+1) * sizeof(char));
	fscanf(file, "%[^,]s", string);
	fseek(file, 1, SEEK_CUR);
	return string;
}

char *read_cidade(FILE *file, int *tamanho){
	char *string;
	string = read_field(file, 50);
	printf("ok\n");
	*tamanho = strlen(string);
	printf("esse strlen aqui\n");
	printf("tamanho = %d", *tamanho);
	return string;
}

int main(){
	FILE *file = NULL;
	file = fopen("arq02.csv", "r");
	if(file == NULL){
		printf("Nao pode abrir\n");
		exit(1);
	}
	fseek(file,0 , SEEK_SET);
	char *string;
	for(int i=0; i<2; i++){
		int *tam = (int *)malloc(sizeof(int));
		string = read_cidade(file, tam);
		printf("%d", *tam);
		printf("%s\n", string);
	}
	free(string);
	fclose(file);
	return 0;
}

