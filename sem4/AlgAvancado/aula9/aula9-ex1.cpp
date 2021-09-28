#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 200000

int MEMO[2][MAX+1];
int N;
vector<int> perm1, perm2;

int solve()
{
	for(int i=0; i<=N; i++)
		MEMO[0][i] = i;
	for(int i=1; i<=N; i++){
		for(int j=0; j<=N; j++){
			if(j == 0) 
				MEMO[i % 2][j] = i;
			else if(perm1[i-1] == perm2[j-1])
				MEMO[i % 2][j] = MEMO[(i-1) % 2][j-1];
			else 
				MEMO[i % 2][j] = 1 + min(MEMO[(i-1) % 2][j], MEMO[i % 2][j-1]);
		}
	}
	return MEMO[N % 2][N];
}

int main()
{
	int T; cin >> T;
	for(int t=0; t<T; t++)
	{
		perm1.clear();
		perm2.clear();
		cin >> N;
		//MEMO.resize(N+1, vector<int>(N+1));
		/*for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				MEMO[i][j] = -1;
		*/
		memset(MEMO, 0, sizeof(MEMO));
		for(int n=0; n<N; n++)
		{
			int temp;
			cin >> temp;
			perm1.push_back(temp);
		}
		for(int n=0; n<N; n++)
		{
			int temp;
			cin >> temp;
			perm2.push_back(temp);
		}
		printf("Case %d: %d\n", (t+1), solve());
	//	cout << "Case " << (t+1) << ": " << solve() << endl;
	}
	return 0;
}
