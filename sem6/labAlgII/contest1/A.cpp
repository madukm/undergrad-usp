#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second

int n;
vector<int> numbers;

void solve() {
	set<int> check;
	vector<int> perm;
	check.clear();
	perm.clear();
	for(auto x : numbers){
		auto added = check.insert(x);
		if(added.ss){
//			cout << "adding " << x << endl;
			perm.push_back(x);
		}
	}
	for(auto x : perm){
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while(t--) {
		cin>>n;
		numbers.clear();
		for(int i=0; i<2*n; i++) {
			int temp; cin>>temp;
			numbers.push_back(temp);
		}
		solve();
	}
}
