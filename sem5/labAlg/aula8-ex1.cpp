#include <iostream> 
#include <cstring> 

using namespace std; 

#define MAX 5000 
#define MIN(a,b,c)  min(min((a), (b)), (c))  

char str1[MAX]; char str2[MAX]; 
int tstr1; int tstr2;
int delta = 1;

int MEMO[MAX+1][MAX+1];

void printM(){
	for (int j = tstr2; j >= 0 ; j--){
		for (int i = 0; i <= tstr1; i++)
			printf("\t%d ", MEMO[i][j]);
		printf("\n");
	}
	printf("\n");
}

int alpha(int i, int j){
	int res;
	char c1 = str1[i];
	char c2 = str2[j];
	if (c1 == c2)
	  res = 0;
    else if ( (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u')  && 
		 (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u') )
		res =  1;
	else if ( !(c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u')  && 
		 !(c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u') )
			res = 1;
		 else res = 3;

	return res;
}

int alin(int i, int j){
	if(i == 0)
	{
		MEMO[0][j] =  j * delta;
		return MEMO[0][j];
	}
	if(j == 0)
	{
		MEMO[i][0] =  i * delta;
		return MEMO[i][0];
	}
	if (MEMO[i][j] != -1)
		return MEMO[i][j];

	MEMO[i][j] = MIN( alpha(i-1, j-1) + alin(i-1, j-1), delta + alin(i-1, j), delta + alin(i, j-1));

	return MEMO[i][j];
}



int main()
{
	scanf("%s", str1);
	scanf("%s", str2);
	tstr1 = strlen(str1);
	tstr2 = strlen(str2);
	memset(MEMO, -1, sizeof MEMO);
	cout << alin(tstr1, tstr2) << endl;

	return 0;
}
