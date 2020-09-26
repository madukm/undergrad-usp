//CDs 

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> tracks;


//Compares if the solution with the curr_track is better than the solution without it.
pair<int, vector<int>> best_solution(int n_track, pair<int, vector<int>> solution)
{
	
	auto curr_sol = solution;
		
	for(int i=n_track; i<int(tracks.size()); i++){
	
		int curr_sum = solution.first + tracks[i]; //sum of solution + curr_track
		
		if(curr_sum <= N){ //if it's valid, so the sum cannot be over N, we'll check which solution is better
			pair<int, vector<int>> aux = make_pair(curr_sum, solution.second);
			aux.second.push_back(tracks[i]);
			auto other_sol = best_solution(i+1, aux);

			if(other_sol.first > curr_sol.first) 
				curr_sol = other_sol;
		}
	
	}	//if the curr_sum is over N, than we just return the previous solution without adding the curr_track
	
	return curr_sol;
}


int main(){
	int n_tracks;
	vector<int> sol;

	while(cin >> N >> n_tracks)
	{
		tracks.clear();
		while(n_tracks--){
			int aux;
			cin >> aux; 
			tracks.push_back(aux);
		}
		sol.clear();
		pair<int, vector<int>> best = best_solution(0, make_pair(0, sol));

		for(int i=0; i<int(best.second.size()); ++i)
			cout << best.second[i] << " ";

		cout << "sum:" << best.first << endl;
	}

	return 0;
}
