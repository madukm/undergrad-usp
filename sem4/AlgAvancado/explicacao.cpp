//IDS => iterative deepening search
//DLS => depth limited search


#define MAX 10 //profundidade da árvore

bool DLS(curr, fim , g, h){
	if(curr == fim) return true;
	if(lim <= 0) return false;
	
	if(g+h > lim){ //o f nao pode exceder o limite, entao pega o proximo menor limite
		plim = min(g+h, plim)
		return false;
	}
	para cada estado E derivado de curr{
		if(DLS(E, fim, g(E), h(E))) return true;
	}
	return false;
}

bool IDS(ini, fim, MAX){
	for(int i=0; i<=MAX; i++)
		if(DLS(ini, fim, i)) return true;
	return false;
	
}

//A*: f(n) = g(n) + h(n)
//g = quao diferente está pro resultado esperado
//h = distancia que estou do fim => valor que nunca é maior que o valor real

int lim, plim; //prox_lim

int IDA*(inicio, fim, MAX){
	lim = g(inicio) + h(inicio);
	while(true){
		// faça a limpeza dos dados
		plim = INF;
		if( DLS(inicio, fim, g(inicio), h(inicio)) ) return lim;
		if(plim == INF) return -1;
		lim = plim; //atualizar limite pra próxima passada
	}
}
