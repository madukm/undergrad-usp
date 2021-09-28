#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int N;
vector<int> target, ini;
int forbidden[10][10][10][10] = {0};

class Code{
	public:		
		int digit[4];
		int h;
		int depth;
		
		//Methods
		Code(): depth(0){}
		~Code(){}
	
		void heuristic(){
			h = 0;
			for(int i=0; i<4; i++)
				h += min(abs(digit[i]-target[i]), 10-abs(digit[i]-target[i]));
			h = h + depth;
		}

		Code(vector<int> x){
			digit[0] = x[0];
			digit[1] = x[1];
			digit[2] = x[2];
			digit[3] = x[3];
			depth = 0;
			heuristic();
		}
	
		bool operator < (Code const& c1) const{
			return c1.h < this->h;
		}
};

void print_pq(priority_queue<Code> pq){
	priority_queue<Code> q = pq;
	cout << "PQ" << endl;
	while(!q.empty()){
		for(int i=0; i<4; i++)
			cout << q.top().digit[i];
		cout << "h = " << q.top().h << endl;
		cout << endl;
		q.pop();
	}
	cout << "END PQ" << endl;
}
int passos(){

	Code initial(ini);
	priority_queue<Code> pq;

	pq.push(initial);

	while(!pq.empty()){
		
		Code curr = pq.top();
		
		if(check_target(curr)) //found the target :)
		   	return curr.depth;
		
		pq.pop();
	
		for(int i=0; i<8; i++){
			Code neighbour = curr;
			neighbour.digit[i/2] = curr.digit[i/2] + (i%2==0 ? 1 : -1);	
			
			if(neighbour.digit[i/2] > 9) neighbour.digit[i/2] = 0;
			if(neighbour.digit[i/2] < 0) neighbour.digit[i/2] = 9;
			
			if(!forbidden[neighbour.digit[0]][neighbour.digit[1]][neighbour.digit[2]][neighbour.digit[3]]){
				forbidden[neighbour.digit[0]][neighbour.digit[1]][neighbour.digit[2]][neighbour.digit[3]] = 1;
				neighbour.depth = curr.depth+1;
				neighbour.heuristic();
				pq.push(neighbour);
			}
		}	
	}

	return -1; //impossible
}

int main(){
	cin >> N;
	int aux;
	while(N--)
	{	
		ini.clear();
		target.clear();
		memset(forbidden, 0, sizeof forbidden);
		for(int i=0; i<4; i++){
			cin >> aux;
			ini.push_back(aux);	
		}
		for(int i=0; i<4; i++){
			cin >> aux;
			target.push_back(aux);
		}
		
		int n_forbidden;
		cin >> n_forbidden;
		for(int i=0; i<n_forbidden; i++){
			int aux1, aux2, aux3, aux4;
			cin>>aux1>>aux2>>aux3>>aux4;
			forbidden[aux1][aux2][aux3][aux4] = 1;
		}
		cout << passos() << endl;

	}
	return 0;
}
