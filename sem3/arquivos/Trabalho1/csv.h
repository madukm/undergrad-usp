#ifndef _H_CSV
#define _H_CSV

struct _registro{
	char *cidadeMae;
	char *cidadeBebe;
	int idNascimento;
	int idadeMae;
	char dataNascimento[10];
	char sexoBebe;
	char estadoMae[2];
	char estadoBebe[2];
};

typedef struct _registro Registro;

struct _cabecalho{
	int stats;
	int topo; //pilha RRN
	Registro *lidos;
};

typedef struct _cabecalho Cabecalho;

//Funcionalidade 1:
char *read_field(FILE *csv); //le cada espaco do registro, separado por , ou \n

//Funcionalidade 2:

#endif
