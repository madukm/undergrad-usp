#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//auxiliary function used for sorting
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

//if the women prefers m2 over m1, return true
bool wPrefersAnother(int n, vector<vector<int>> preferences, int w, int m1, int m2)
{
	for(int i=0; i<n; i++){
		if(preferences[w-1][i] == m1) return false;
		if(preferences[w-1][i] == m2) return true;
	}
	return true;
}

void stable_marriage(int n, vector<vector<int>> preferences)
{
	vector<pair<int, int>> marriage(n); // (woman, man)
	vector<queue<int>> w_not_proposed(n); //women not proposed by the men 
	queue<int> free_man; 
	
	int curr_m, curr_w;
	
	for(int i=0; i<n; i++){
		free_man.push(i+1); //putting all man in the queue
		marriage[i].first = i+1; //putting all woman as the first in the pair
		for(int j=0; j<n; j++)
			w_not_proposed[i].push(preferences[i+n][j]); //putting all women in order of preference of each man
	}

	//while there are men single
	while(!free_man.empty())
	{
		curr_m = free_man.front();
		
		if(w_not_proposed[curr_m-1].empty()) break;

		curr_w = w_not_proposed[curr_m-1].front(); //first woman on the list of the curr_m
		int fiance = marriage[curr_w-1].second; //current fiance of the woman (0 means she is single)

		if(fiance == 0){ //single
			marriage[curr_w-1].second = curr_m;
			free_man.pop();
		}
		else{
			if(wPrefersAnother(n, preferences, curr_w, fiance, curr_m)){
				marriage[curr_w-1].second = curr_m; //curr_m gets engaged with the woman
				free_man.pop();
				free_man.push(fiance); // her ex-fiance is single now
			}
		}
		w_not_proposed[curr_m-1].pop(); //curr_w is not on the list to propose anymore
	}

	sort(marriage.begin(), marriage.end(), sortbysec); //sorting by the second of the pair just to match the output wanted
	for(int i=0; i<n; i++)
		cout << marriage[i].second << " " << marriage[i].first << endl;
}

int main()
{
	int t, n;
	cin >> t;
	
	for(int i=0; i<t; i++){
		//preferences of women and men
		cin >> n;
		vector<vector<int>> preferences(2*n); //women first than men
		for(int i=0; i<2*n; i++){
			preferences[i].resize(n);
			int index;
			int pref;
			cin >> index;
			for(int j=0; j<n; j++){
				cin >> pref;
				preferences[i][j] = pref;
			}
		}
		stable_marriage(n, preferences);
	}

	return 0;
}
