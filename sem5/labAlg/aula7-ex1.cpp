#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

int main()
{
	ll n, x;
	int mod = 1e9+7;
	cin >> n >> x;
	vector<ll> coins(n);
	for(int i=0; i<n; i++)
	{
		cin >> coins[i];
	}
	vector<ll> dp(x+1, 0);
	
	dp[0] = 1;
	
	for(ll i=1; i<=x; i++)
	{
		for(ll j=0; j<n; j++)
		{
			if(i-coins[j] >= 0)
			{
				dp[i] += dp[i-coins[j]];
				dp[i] %= mod;
			}
		}
	}
	cout << dp[x] << endl;
	return 0;
}
