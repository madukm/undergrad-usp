//MOEDAS PD

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define inf 100000

/*int coins(int v){
	if(v == 0) return 0;
	for(int i=0; i<MAX; i++){
		if(moeda <= v)
			menor = min(1+coins(v-moeda[i]), menor);
	}
	return menor;
}*/

int N, V, Q;
vector<int> MEMO;
vector<int> coins;

int min_coins()
{
	for(int i=1; i<=V; i++)
		MEMO[i] = inf;
	MEMO[0] = 0;
	for(int i=1; i<=V; i++){
		for(int j=0; j<Q; j++)
			if(coins[j] <= i)
				MEMO[i] = min(1+MEMO[i-coins[j]], MEMO[i]);
	}
	return MEMO[V];
}


int main(){
	cin >> N;
	while(N--){
		coins.clear();
		MEMO.clear();
		cin >> V >> Q;
		MEMO.resize(V+1);
	   	for(int i=0; i<Q; i++){
			int temp; cin >> temp;
			coins.push_back(temp);
		}	
		cout << min_coins() << endl;
	}
	return 0;
}
