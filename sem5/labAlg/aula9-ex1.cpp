#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
vector<vector<int>> connections;
vector<int> parent, dist;
int MAX = 2e5 + 5;

void bfs(int initial){
    queue<int> bfs;
    bfs.push(initial);
    dist[1] = 0;
    parent[1] = 1;
    while(!bfs.empty()){
        int curr = bfs.front();
        bfs.pop();
        int d = dist[curr] + 1;
        for(int c : connections[curr]){
            if(d >= dist[c])
                continue;
            dist[c] = d;
            parent[c] = curr;
            bfs.push(c);
        }
    }
}

void solve(){
    cin >> n >> m;
    connections.resize(n+1);
    parent.resize(n+1);
    parent[1] = 0;
    dist.resize(n+1);
    for(int i=1; i<=n; i++){
       dist[i] = MAX;
	   parent[i] = -1;
	}
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    bfs(1);
    if(dist[n] > n){
        cout << "IMPOSSIBLE" << endl;
    }else{
		stack<int> ans;
    	while (n > 1){
        	ans.push(n);
        	n = parent[n];
    	}
    	ans.push(1);
    	cout << ans.size() << endl;
	}
}

int main(){
    solve();
    return 0;
}
