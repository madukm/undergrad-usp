#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tamCrivo;

bitset<100010> bs;
vector<ll> primos;
int fatores[100];

void fatoresPrimos(ll n){
	int index = 0;
	for(int p=primos[index]; p*p<=n; p=primos[++index]){
		while(n % p == 0){
			fatores[p]++;
			n = n/p;
		}		
	}
	if(n != 1) fatores[n]++;
}

void crivo(ll n){
	tamCrivo = n+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= tamCrivo; i++){
		if(bs[i]){ 
			for (ll j = i*i; j <= tamCrivo; j+=i)
				bs[j] = 0;
			primos.push_back(i);
		}	
	}
}

int main()
{
	crivo(100000);
	while(1){
		int n; cin >> n;
	   	if(n == 0) break;	
		cout<<right<<setw(3) << n << "! =";
		memset(fatores, 0, sizeof(fatores));
		while(n != 0){	
			fatoresPrimos(n);
			n--;
		}
		int c = 0;
		for(int i = 0; i<100; i++){
			if(fatores[i] != 0){
				if(c == 15){
					c = 0;
					cout << "\n      ";
				}
				cout<<right<<setw(3) << fatores[i];
				c++;
			}
		}
		printf("\n");
	}
	return 0;
}
