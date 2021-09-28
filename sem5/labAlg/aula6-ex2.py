#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int p, q, r, s, t, u;

double equation(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u;
}

double bisection(double lo, double hi){
	if(equation(lo) * equation(hi) > 0) return -1;
	while(hi-lo > double(0.00000001)){
		double center = (hi+lo)/2;
		if(equation(center) <= 0)
			hi = center;
		else lo = center;
	}
	return (lo+hi)/2;
}

int main(){
	while(cin >> p >> q >> r >> s >> t >> u){
		double res = bisection(0., 1.);
		if(res >= 0)	printf("%.4lf\n", res);
		else cout << "No solution" << endl;
	}

	return 0;
}
