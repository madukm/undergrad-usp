#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second

ll n;
unordered_map<string, ll> r;

void solve() {
	string x; cin>>x;
	if(r.find(x) == r.end()){
		r[x] = 1;
		cout << "OK" << endl;
	} else {
		cout << x << r[x]++ << endl;
	}		
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	while(n--)
		solve();
}
