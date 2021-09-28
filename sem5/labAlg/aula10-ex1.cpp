#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define ll long long

struct _aresta{
    ll dis;
    ll x, y;
};

bool comp(_aresta a, _aresta b){ return a.dis < b.dis; }

#define MAXN 100010
#define MAXM 200010

ll n, m;
_aresta aresta[MAXM];

ll father[MAXN];
ll weight[MAXN];

_aresta mst[MAXM];

ll find(ll x){

	if(father[x] == x) return x;
	return father[x] = find(father[x]);

}

void join(ll a, ll b){    
    
	a = find(a);
    b = find(b);
   	if(a != b)
		father[a] = b;

}

int main(){
    
	cin >> n >> m;
    for(ll i = 1; i <= m; i++)
    	cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
    
    for(ll i = 1; i <= n; i++) 
		father[i] = i;
    
    sort(aresta+1, aresta+m+1, comp);
    
    ll size = 0;
    for(ll i = 1; i <= m; i++){
        
        if( find(aresta[i].x) != find(aresta[i].y) ){ 
			join(aresta[i].x, aresta[i].y);            
            mst[++size] = aresta[i];
        }
        
    }
	if(size < n-1){
		printf("IMPOSSIBLE\n");
		return 0;
	}

    ll sum = 0;
    
	for(ll i = 1;i < n;i++){
		sum += mst[i].dis;
	}

	cout << sum << endl;
	
	return 0;

}
