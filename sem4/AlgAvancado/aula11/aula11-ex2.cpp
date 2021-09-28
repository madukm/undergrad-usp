#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <map>

using namespace std;

typedef long long unsigned int llu; 

map<llu, llu> fatores;

void fatoresPrimos(llu n);

int main(){
	
	int n, m;
	while(cin >> n >> m){
		fatores.clear();
		if(m==0){
 			cout << m << " does not divide " << n << "!" << endl;
			continue;
		}else if(n==0){
			if(m==1) cout << m << " divides " << n << "!" << endl;
			else cout << m << " does not divide " << n << "!" << endl;
			continue;
		}
	
		fatoresPrimos(m);
		
		bool divide = true;
		for(map<llu, llu>::iterator t = fatores.begin(); t!=fatores.end(); ++t){
			llu c = 0;
			llu temp = t->first;
			while(n/temp != 0){
				c += n/temp;
				temp *= t->first;
			}
			if(t->second > c){
				cout << m << " does not divide " << n << "!" << endl;
				divide = false;
				break;
			}
		}
		if(divide) cout << m << " divides " << n << "!" << endl;
	}
	return 0;
}

void fatoresPrimos(llu n){
	llu t = n;
	while(t%2==0){
		fatores[2]++;
		t = t/2;
	}
	llu i = 3;
	double raiz = sqrt(t);
	while(i<=raiz){
		if(t%i==0){
			fatores[i]++;
			t = t/i;
			raiz = sqrt(t);
		}
		else i+=2;
	}
	if(t > 1) fatores[t]++;
}

