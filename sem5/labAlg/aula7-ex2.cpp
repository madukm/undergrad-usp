#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack(int mw, int price[], int weight[], int N)
{
	int K[N+1][mw+1];
	for(int i=0; i<=N; i++)
	{
		for(int w=0; w<=mw; w++)
		{
			if(i==0 || w==0) 
				K[i][w] = 0;
			else if(price[i-1] <= w)
				K[i][w] = max(weight[i-1]+K[i-1][w-price[i-1]], K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
	return K[N][mw];
}

int main()
{
	int T, N;
	cin >> T;
   	while(T--)
	{
		cin >> N;
		vector<int> obj(N);	
		int price[N], weight[N];
		for(int j=0; j<N; j++)
		{
			cin >> price[j] >> weight[j];
		}
		int G, mw;
		int total = 0;
		cin >> G;
		for(int i=0; i<G; i++)
		{
			cin >> mw;
			total += knapsack(mw, weight, price, N);
		}
		cout << total << endl;		
	}
	return 0;
}
