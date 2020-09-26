// STATION BALANCE

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

float imbalance(int C, vector<pair<int, int>> chambers){
	float AM = 0; //Average Mass of the chambers
	
	for(int i=0; i<C; ++i)
		AM = AM + chambers[i].first + chambers[i].second;
	
	AM = AM/C;
	
	float imbalance_value = 0;

	for(int i=0; i<C; ++i)
		imbalance_value += fabs(AM-(chambers[i].first + chambers[i].second));
	
	return imbalance_value;
}

void organize(int C, vector<int> masses){
	
	int S = masses.size();
	vector<pair<int, int>> sets;
	
	if(S < 2*C){
		for(int i=0; i<2*C-S; i++)
			masses.push_back(0); //filling the masses until they are 2C
	}

	sort(masses.begin(), masses.end());
	
	for(int i=0; i<C; i++) //putting each mass in its respective chambers
		sets.push_back(make_pair(masses[i], masses[2*C-1-i]));
	
	for(int i=0; i<C; i++){
		printf(" %d:", i);
		if(sets[i].first != 0)
			printf(" %d", sets[i].first);
		if(sets[i].second != 0)
			printf(" %d", sets[i].second);
		cout << endl;
	}

	printf("IMBALANCE = %.5f\n\n", imbalance(C, sets));
	
}

int main(){
	int C, S;
	int counter = 1; //just for output
	while(cin >> C >> S) //until there is no more inputs
	{
		vector<int> masses;
		int masses_aux;

		while(S--){
			cin >> masses_aux;
			masses.push_back(masses_aux);
		}

		cout << "Set #" << counter++ << endl;	
		
		organize(C, masses);
	}

	return 0;
}

