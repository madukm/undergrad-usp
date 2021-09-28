#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define inf 1000000000
#define vi vector<int>
#define vii vector<vector<int>>

vii input;
int n;
int memo[1000];

int dp(int i)
{
    int &ret = memo[i];
    if(ret != -1) 
		return ret;
    ret = 1;
    for(int j=i+1; j<n; j++)
        if(input[j][0] > input[i][0] && input[j][1] < input[i][1])
		   	ret = max(ret, 1 + dp(j));
    return ret;
}

int main()
{
    vi temp(2);
    
	while(scanf("%d%d", &temp[0], &temp[1]) == 2)
	{
		input.push_back(temp);
    }
    
	n = input.size();

    sort(input.begin(), input.end());
    memset(memo, -1, sizeof memo);
    
	int largest = 0;
    for(int i=0; i<n; i++)
	{
        largest = max(largest, dp(i));
	}
	
	cout << largest << endl;
   	return 0;
}
