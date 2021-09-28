#include <iostream>
#include <vector>

#define inf 1000000

using namespace std;

vector<int> vec;
vector<int> L, R, A;

int inv(int ini, int meio, int fim){
	if(ini == fim) return 0;
	int cont = 0;
	int n1 = meio-ini+1;
	int n2 = fim-meio;
	L.resize(n1+1);
  	R.resize(n2+1);
  	for(int i=0; i<n1; i++)
  	  	L[i] = vec[ini+i];
  	for(int i=0; i<n2; i++)
  	  	R[i] = vec[meio+i+1];
  	L[n1] = inf;
  	R[n2] = inf;
  	int k = ini;
  	int i = 0, j = 0;
  	while(k <= fim){
  	  	if(L[i] < R[j]){
  	    	A[k++] = L[i++];
  	  	}
  	  	else{
			cont += (n1 - i);
			A[k++] = R[j++];
  		}
  	}
	for(i=ini; i<=fim; i++)
		vec[i] = A[i];
	L.clear();
	R.clear();
	return cont;
}	

int inversions(int ini, int fim){
	if(ini >= fim) return 0;	
	int c = 0;
	int meio = (ini+fim)/2;
	c += inversions(ini, meio);
	c += inversions(meio+1, fim);
    c += inv(ini, meio, fim);
	return c; 
}

void test(){

}

int main(){
	int N;
	cin >> N;
	int C;
	while(N--){
		cin >> C;
		vec.clear();
		A.resize(C);
		for(int i=0; i<C; i++){
			int aux;
			cin >> aux;
			vec.push_back(aux);
		}
		cout << inversions(0, C-1) << endl;
	}
	return 0;
}
