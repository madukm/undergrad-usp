//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <cstring>

using namespace std;

vector<int> weight;
int memo[20+1][200+1];

int solve(int n, int w){
	for(int i=1; i<=n; i++){
		for(int peso=0; peso<=w; peso++){
			if(weight[i] > peso)
				memo[i][peso] = memo[i-1][peso];
			else
				memo[i][peso] = max(memo[i-1][peso], weight[i] + memo[i-1][peso-weight[i]]);
		}
	}
	return memo[n][w];
}

int main(){
	int M; cin >> M;
	string line;
	getline(cin, line);
	while(M--)
	{
		weight.clear();
		getline(cin, line);
		istringstream iss(line);
		
		int sum = 0;
	   	for(int n; iss >> n; ){
			weight.push_back(n);
			sum += n;
		}

		if(sum % 2 == 1){
			cout << "NO" << endl;
			continue;
		}
		
		memset(memo, -1, sizeof(memo));
		
		for(int w=0; w<=200; w++)
			memo[0][w] = 0;
	
		int result = solve(weight.size()-1, sum/2);
		
		if(result == sum/2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
