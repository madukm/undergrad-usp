#include <iostream>

#define MAXSIZE 500001

using namespace std;

int n, m, k, u;
int p[MAXSIZE], dist[MAXSIZE];

int rec(int x){ 
	return p[x] == x ? x : p[x] = rec(p[x]);
}

int main(){
    cin>>n>>m;
	for(int i=1; i<(n+m+1); i++)
		p[i] = i;
	for(int i=1; i<(m+1); i++){
		for(cin>>k; k>0; k--){
			cin >> u;
			p[rec(u)] = rec(n+i);
		}
	}
	for(int i=1; i<(n+1); i++)
		p[i] = rec(i);
	for(int i=1; i<(n+1); i++)
		dist[p[i]]++;
	for(int i=1; i<(n+1); i++)
		cout << dist[p[i]] << ' ';
	cout << endl;
    return 0;
}
