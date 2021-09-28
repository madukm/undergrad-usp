#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 6

int V[MAX+1] = {0, 2, 4, 4, 7, 2, 1};
int p[MAX+1] = {-1, 0, 0, 1, 0, 3, 3};
//Estrutura de memória auxiliar para armazenar resultados parciais em pd
//se chama memoização (não é memorização)
int MEMO[MAX+1];

int wispRec(int j){
	if(j == 0) return 0;
	
	if(MEMO[j] != -1) return MEMO[j];

	MEMO[j] = max(V[j] + wispRec(p[j]), wispRec(j-1));
	
	return MEMO[j];
}

//Daria pra fazer iterativo? esta é a verdadeira pd.
//A melhor resposta sempre vai estar no ultimo.
//muito toooooop
//
int wisp(){
	for(int j=1; j<=MAX; j++) //começa no 1
		MEMO[j] = max(V[j] + MEMO[p[j]], MEMO[j-1]); 	
	
	return MEMO[MAX];
}




int main(int argc, char const *argv[]){
	MEMO[0] = 0;
	cout << "O maior valor é " << wisp() << endl;
}





//MOEDAS

MAX = 4;
V = 7;
moedas[MAX] = {5, 3, 4, 1};

f(n) = MAX(vn + f(p[n]), f(n-1))

o q seria o n neste nosso caso? 
qual a condição de fronteira ou as condições
o q seria minha função f de minimização n DIFERENTE da condição de fronteira.

//teremos um vetor de valores....
//f(n) é com relação aos valores
//f(0) = 0 // se o troco é zero n tem mais moeda pra dar...
//VALOR - moeda
//f(n<0) = INFINITO....
//else if
//f(n) : min(1+f(valor-moeda[i])), para toda moeda i 

int coins(int v){
	if(v == 0) return 0;
	for(int i=0; i<MAX; i++){
		if(moeda <= v)
			menor = min(1+coins(v-moeda[i]), menor);
	}
	return menor;
}

//fazer recursivo pd e depois fazer iterativo.

RUN CODES:
