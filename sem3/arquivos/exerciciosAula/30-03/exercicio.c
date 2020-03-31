#include <stdio.h>
#include <stdlib.h>

void insert_register(FILE *file);
void read_registers(FILE *file);

int main(){
	FILE *file;
	file = fopen("produtos.bin", "w+b");
	int option;

	while(1){
		printf("\n---MENU---\n");
	        printf("Digite:\n1: inserir um registro\n2: ler os registros\n3: sair do programa\n");
        	scanf("%d", &option);
		if(option == 1)
			insert_register(file);
		else if(option == 2)
			read_registers(file);
		else{
			fclose(file);
			return 0;
		}
	}
}


void insert_register(FILE *file){
        char nome[40], marca[30];
        long long int ean13;
        float valor;
        printf("\nEscreva o nome do produto: ");
        scanf("%s", nome);
        fwrite(nome, sizeof(char), 40, file);
        printf("\nEscreva o nome da marca: ");
        scanf("%s", marca);
        fwrite(marca, sizeof(char), 30, file);
        printf("\nEscreva o código de 13 dígitos: ");
        scanf("%lld", &ean13);
        fwrite(&ean13, sizeof(long int), 1, file);
        printf("\nEscreva o valor do produto: ");
        scanf("%f", &valor);
        fwrite(&valor, sizeof(float), 1, file);

}

void read_registers(FILE *file){
        char nome[40], marca[30];
        float valor;
        long long int ean13;
        fseek(file, 0, SEEK_SET); //vai pro começo do arquivo
        while(fread(nome, sizeof(char), 40, file) != 0){ //para quando chega no final do arquivo
                printf("\nNome: %s", nome);
                fread(marca, sizeof(char), 30, file);
                printf("\nMarca: %s", marca);
                fread(&ean13, sizeof(long long int), 1, file);
                printf("\nEAN13: %lld", ean13);
                fread(&valor, sizeof(float), 1, file);
                printf("\nValor: %f\n", valor);
        }
}

