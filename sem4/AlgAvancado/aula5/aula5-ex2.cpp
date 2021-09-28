#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<int> heights;

void mates(int x, int ini, int fim){
	if(ini>fim){
		if(heights[fim] < x){
			cout << heights[fim] << " ";
			if(fim < N - 1) cout << heights[fim+1];
			else cout << "X";
		}
		if(heights[fim] > x){
			if(fim > 0) cout << heights[fim-1] << " ";
		   	else cout << "X" << " ";
			cout << heights[fim];
		}
		cout << endl;
		return;
	}
    else{
    	int m = (ini+fim)/2;
    	if (heights[m] == x){
			if(m > 0)
				cout << heights[m-1] << " ";
		   	else cout << "X" << " ";
			if(m < N-1)
				cout << heights[m+1] << endl;
			else cout << "X" << endl;
			return;
		}
    	if (heights[m] < x) return mates(x, m+1, fim);
    	else return mates(x, ini, m-1);
	}
}


int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		int aux;
		cin >> aux;
		heights.push_back(aux);
	}
	vector<int>::iterator it;
	it = unique(heights.begin(), heights.end());
	heights.resize( distance(heights.begin(),it) );
	N = int(heights.size());
	cin >> Q;
	while(Q--){
		int query;
		cin >> query;
		mates(query, 0, N-1);
	}
	return 0;
}
