// COIN COLLECTOR

#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int maximum_coins(vector<long int> coins){
	
	if(coins.size() == 1) return 1;

	int number_coins = 2; //the coin of smallest and highest value will always join
	int money = 1; //the first coin is always 1
	
	for(unsigned int i=1; i<coins.size()-1; i++){
		if(money + coins[i] < coins[i+1]){
			number_coins++;
			money += coins[i];
		}
	}

	return number_coins;
}

int main(){
	int T, n;
	cin >> T;
	while(T--){
		vector<long int> coins;
		cin >> n;
		for(int i=0; i<n; i++){
			int coin_value;
			cin >> coin_value;
			coins.push_back(coin_value);
		}
		int max_coins = maximum_coins(coins);
		cout << max_coins << endl;
	}

	return 0;
}
