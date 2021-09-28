#include <stdio.h>
#include <string.h>
#include "lib/manage_bin/manage_bin.h"
#include "lib/manage_csv/manage_csv.h"
#include "lib/binarioNaTela/binarioNaTela.h"
#include "lib/funcionalidades/funcionalidades.h"

int main(int argc, char const *argv[]){
	Cabecalho *cab = NULL;
	int input_op;
	char path_1[100];
//	char path_2[100];

	int n;
	scanf("%d%s", &input_op, path_1);
	switch(input_op){
		case 6:
			scanf("%d", &n);
			funcionalidade6(path_1, cab, n);
			break;
		case 7:
			scanf("%d", &n);
			funcionalidade7(path_1, cab, n);
			break;
	}
	
	return 0;
}
