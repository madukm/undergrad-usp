#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll tamCrivo;

bitset<10000010> bs;
vector<ll> primos;

void solve(int n){
	
}



void crivo(ll n){
	tamCrivo = n+1;

	bs.set();   //inicia o bit como TRUE....
	bs[0] = bs[1] = 0;

	for (ll i = 2; i <= tamCrivo; i++){  //PERCIREE TODO O CRIVO...
		if (bs[i])  {     //se ele é primo, elimina todos os seus multiplos e coloca no vetor primos.. 
			for (ll j = i*i; j <= tamCrivo; j+=i)
			{
				bs[j] = 0;
			}
			primos.push_back(i);
		}
	
	}

}



int main(int argc, char const *argv[])
{
	/* code */

	crivo (10000000);
	int n; cin >> n;
	

	vi r = fatoresPrimos(n);


	for (vi::iterator i = r.begin(); i != r.end(); i++)
		printf("%d ", *i);
	printf("\n");

	r = fatoresPrimos(n);
	for (vi::iterator i = r.begin(); i != r.end(); i++)
		printf("%d ", *i);
	printf("\n");

	mii m = fatoresPrimosMAP(n);
	for (mii::iterator i = m.begin(); i != m.end(); i++)
		printf("%d -> %d , ", i->first, i->second);
	printf("\n");



	return 0;
}
