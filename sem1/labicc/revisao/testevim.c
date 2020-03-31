#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	char palavra[20];
	scanf("%s", palavra);
	palavra = tolower(palavra);
	printf("%s\n", palavra);
	palavra = toupper(palavra);
	printf("%s\n", palavra);
	printf("vai dar bom a prova\n");
	return 0;
}
