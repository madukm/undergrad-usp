#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define ppll pair<ll, pll>

const ll n_max = 1e5+5;
const ll inf = 1e16;
vector<vector<pll>> adj;
priority_queue< ppll, vector<ppll>, greater<ppll> > pq;
ll visited[n_max][2];
ll dist[n_max][2];

void dijkstra(){
	pq.push({0, {0, 0}});
	while(!pq.empty()){
		ppll curr = pq.top();
		pq.pop();
		if(visited[curr.second.first][curr.second.second]) 
			continue;
		for(auto &i : adj[curr.second.first]){
			if(curr.second.second){
				if(dist[i.first][1] > dist[curr.second.first][1] + i.second){
					dist[i.first][1] = dist[curr.second.first][1] + i.second;
					pq.push({dist[i.first][1], {i.first, 1}});
				}
			}else{
				if(dist[i.first][1] > dist[curr.second.first][1] + i.second){
					dist[i.first][1] = dist[curr.second.first][1] + i.second;
					pq.push({dist[i.first][1], {i.first, 1}});
				}
				if(dist[i.first][0] > dist[curr.second.first][0] + i.second){
					dist[i.first][0] = dist[curr.second.first][0] + i.second;
					pq.push({dist[i.first][0], {i.first, 0}});
				}
				if(dist[i.first][1] > dist[curr.second.first][0] + i.second/2){
					dist[i.first][1] = dist[curr.second.first][0] + i.second/2;
					pq.push({dist[i.first][1], {i.first, 1}});
				}
			}
		}
	}
}

int main(){
	ll n, m;
	cin >> n >> m;
	ll x, y, z;
	fill_n(&dist[0][0], n_max*2, inf);
	dist[0][0] = 0;
	dist[0][1] = 0;
	adj.resize(n+1);
	for(ll i=0; i<m; i++){
		cin >> x >> y >> z;
		x--;
		y--;
		adj[x].push_back({y, z});
	}
	dijkstra();
	cout << min(dist[n-1][0], dist[n-1][1]) << endl;
	return 0;	
}
