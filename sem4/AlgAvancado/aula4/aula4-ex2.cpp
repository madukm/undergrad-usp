#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

int positions[9][2]{{2,2}, {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}};
string target = {"123456780"};
unordered_map<string, int> umap;

struct State{
	string state;
	int depth;
	int h;
	int x;
	queue<char> path;

	State(){}
	~State(){}
	
	bool operator < (State const& s1) const{
		return s1.h < this->h;
	}

	int manhattan(){
		int h_i;
		int h_j;
		int heu = 0;
		for(int i=0; i<9; i++){
			h_i = i/3;
			h_j = i%3;
			heu += abs(positions[state[i] - '0'][0] - h_i) + abs(positions[state[i] - '0'][1] - h_j);
		}
		return heu;
	}

	void heuristic(){
		h = manhattan() + depth;
	}

	State(string state, int x) : state(state), depth(0), x(x){
		heuristic();
	}

	bool check_solvable(){
		int inv = 0;
		for(int i=0; i<8; i++){
			for(int j=i+1; j<9; j++){
				if(state[i]-'0' != 0 && state[j]-'0' != 0 && state[i]-'0' < state[j]-'0')
					inv++;
			}
		}
		if(inv % 2 == 0) return true;
		return false;
	}

};

priority_queue<State> pq;

void print_queue(queue<char> q){
	queue<char> aux = q;
	while(!aux.empty()){
		cout << aux.front();
		aux.pop();
	}
	cout << endl;
}

void add_neighbour(State neighbour, int i, int j, char p){
	if(not((i%3 == j%3) ^ (i/3 == j/3)) || j<0 || j>8) return;
	swap(neighbour.state[i], neighbour.state[j]);
	if(umap[neighbour.state] == 1) return;
	neighbour.path.push(p);
	neighbour.x = j;
	neighbour.depth++;
	neighbour.heuristic();
	umap[neighbour.state] = 1;
	pq.push(neighbour);
}


void passos(string init, int x){
	
	State initial(init, x);
	
	if(!initial.check_solvable()) {
		cout << "unsolvable" << endl;
		return;	
	}
	
	pq.push(initial);

	while(!pq.empty()){
		State curr = pq.top();
		
		if(curr.state.compare(target) == 0){ //found the target :)
		   	print_queue(curr.path);
			return;
		}

		pq.pop();
	
		State neighbour = curr;
		add_neighbour(neighbour, curr.x, curr.x-3, 'u');	
		neighbour = curr;
		add_neighbour(neighbour, curr.x, curr.x-1, 'l');	
		neighbour = curr;
		add_neighbour(neighbour, curr.x, curr.x+3, 'd');	
		neighbour = curr;
		add_neighbour(neighbour, curr.x, curr.x+1, 'r');	
	}

	cout << "unsolvable" << endl; //impossible
}



int main(){
	int N;
	cin >> N;
	while(N--){
		int x = 0;
		stringstream ss;
		ss.str(string());
		umap.clear();
		for(int i=0; i<9; i++) {
            string s; cin >> s;
            if (s=="x") {
				s="0";
				x = i;
			}
			ss << s;
        }
		while(!pq.empty())
			pq.pop();
		string s = ss.str();
		passos(s, x);
		if(N > 0){
			cout << endl;
		}
	}
	return 0;

}
