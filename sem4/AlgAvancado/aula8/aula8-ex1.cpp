#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct doll{
	int w, h;
};


bool cmp(doll a, doll b){
	return (a.w < b.w) || (a.w == b.w && a.h > b.h);
}

vector<int> visited;
vector<struct doll> D; 

int main(){
	int t, m;
	cin >> t;
	while(t--)
	{
		int qty = 0;
		cin >> m;
		D.clear();
		D.resize(m);
		visited.resize(m);	
		for(int i=0; i<m; i++){
			scanf("%d%d", &D[i].w, &D[i].h);
			visited[i] = 0;
		}
		
		sort(D.begin(), D.end(), cmp);
//		for(int i=0; i<m; i++){
//			cout << D[i].w << " " << D[i].h << endl;
//		}

		for(int i=0; i<m; i++){
//			for(int v=0; v<visited.size(); v++)
//				cout << visited[v] << " ";
//			cout << endl;
			if(visited[i] == 1) continue;
			else{
				int curr = i;
				visited[curr] = 1;
				for(int j=curr+1; j<m; j++){
					if(D[curr].h < D[j].h && visited[j] == 0){
						curr = j;
						visited[j] = 1;
					}
				}
				qty++;
			}
		}
		cout << qty << endl;
	}

	return 0;
}
