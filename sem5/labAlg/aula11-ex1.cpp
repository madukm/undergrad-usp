#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define pll pair<ll, ll>

const ll n_max = 1e5+5;
const ll inf = 1e16;
vector<pll> g[n_max];
vector<ll> dist(n_max, inf), visited(n_max, 0);

void dijkstra(){
	priority_queue< pll, vector<pll>, greater<pll> > pq;
	dist[1] = 0;
	pq.push({0, 1});
	while(!pq.empty()){
		pll curr = pq.top();
		pq.pop();
		if(visited[curr.second]) // if already visited, continue 
			continue;
		visited[curr.second] = 1; // if not visited, mark as visited
		for(auto &i : g[curr.second]){
			if(!visited[i.first]){
				if(dist[i.first] > curr.first + i.second){
					dist[i.first] = curr.first + i.second;
					pq.push({dist[i.first], i.first});
				}
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
    for(ll i = 1; i <= m; i++){
    	int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	dijkstra();
	for(int i=1; i<=n; i++){
		cout << dist[i] << " ";
	}
	return 0;	
}
