#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 2000

int MEMO[MAX+1][MAX+1];
string str1, str2;
int n, m;

int solve()
{
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i == 0 && j == 0)
				continue; //if both strings are empty, then it's zero.
			else if(i == 0)
				MEMO[i][j] = MEMO[i][j-1] + str2[j-1] - 96;
			else if(j == 0)
				MEMO[i][j] = MEMO[i-1][j] + str1[i-1] - 96;
			else if(str1[i-1] == str2[j-1])
				MEMO[i][j] = MEMO[i-1][j-1];
			else
				MEMO[i][j] = min(MEMO[i-1][j] + str1[i-1] - 96, min(MEMO[i][j-1] + str2[j-1] - 96, MEMO[i-1][j-1] + abs(str1[i-1] - str2[j-1])) );
		}
	}
	return MEMO[n][m];
}

int main()
{
	cin >> str1 >> str2;	
	n = str1.length();
	m = str2.length();
	memset(MEMO, 0, sizeof(MEMO));
	cout << solve() << endl;
	return 0;
}
