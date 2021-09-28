#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second

int N;
vector<pair<ll, ll>> activities;

bool sortByEnd(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return (a.ss < b.ss);
}

void solve() {
	sort(activities.begin(), activities.end(), sortByEnd);
	ll max_num = 1;
	ll last = 0;
	for(int i=1; i<N; i++) {
		if(activities[i].ff >= activities[last].ss){
			max_num++;
			last = i;
		}
	}
	cout << max_num << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	while(T--) {
		cin>>N;
		activities.clear();
		for(int i=0; i<N; i++) {
			int n, m; cin>>n>>m;
			activities.push_back(make_pair(n, m));
		}
		solve();
	}
}
