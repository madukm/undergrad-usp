#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"


char *read_field(FILE *csv){
	int byte, tamanho = 0;
	char *string = NULL;
	while(byte = fgetc(csv) != EOF){
		if(byte == ',')
			break;
		string = realloc(string, tamanho + 1);
		tamanho++;
		string[tamanho-1] = byte;
	}
	string = realloc(string, tamanho + 1);
	string[tamanho] = '\0';
	printf("tam = %d", tamanho);
	return string;
}



int main(){
	FILE *arq;
	if(arq = fopen("arq02.csv", "r") == NULL){
		exit(1);
	}
	for(int i=0; i<8; i++)
		printf("%s",read_field(arq));
	fclose(arq);
	return 0;
}
