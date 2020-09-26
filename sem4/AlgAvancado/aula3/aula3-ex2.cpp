#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<vector<int>> map;

int paths(int x, int y){
	
	int n_paths = 0;

	if(x >= N || y>= N || x<0 || y<0) return 0; //not a valid path
	if(map[x][y] == 1) return 0; //blocked
	if(x == N-1 && y == N-1) return 1; //found a path :)
	
	map[x][y] = 1; //mark as visited so it doesn't go back and forth

	n_paths += paths(x+1, y);//R
	n_paths += paths(x, y+1);//U
	n_paths += paths(x-1, y);//L
	n_paths += paths(x, y-1);//D
	
	map[x][y] = 0; //undo visited so it doesn't interfere in another path

	return n_paths;
}

int main(){
	cin >> N;
	map.resize(N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int aux;
			cin >> aux;
			map[i].push_back(aux);
		}
	}
	cout << paths(0, 0) << endl;

	return 0;
}
