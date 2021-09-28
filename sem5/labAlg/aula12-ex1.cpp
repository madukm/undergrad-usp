// Maria Eduarda Kawakami Moreira - 11218751
// Aula 12

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
map <ll, ll> factors;

#define abs_val(a)       (((a)>0)?(a):-(a))

ll mulMod(ll a, ll b, ll c)
{
    ll x = 0, y = a%c;
    while (b > 0)
    {
        if (b%2 == 1)
            x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

ll gcd(ll a, ll b)
{
     return !b ? a : gcd(b, a%b);
}

ll Mod(ll a, ll b, ll p)
{
    ll res = 1;
    ll x = a%p;

    while (b)
    {
        if (b&1)
        {
            res = mulMod(res, x, p);
        }
        x = mulMod(x, x, p);
        b /= 2;
    }
    return res%p;
}


bool millerTest(ll d, ll s, ll n)
{
    ll a = rand() % (n-4) + 2;
    ll x = Mod(a, s, n);

    if (x==1 or x==n-1)
        return true;

    for (int r = 1; r < d; r++)
    {
        x = mulMod(x, x, n);

        if (x==1)
            return false;
        if (x==n-1)
            return true;
    }
    return false;
}


bool isPrime(ll n, int k = 20)
{
    if (n <= 1 || n==4)
        return false;
    if (n<=3)
        return true;
    if (n%2==0)
        return false;

    ll s = n-1, d = 0;
    while (s%2==0)
    {
        s/=2;
        d++;
    }
    for (int i = 0; i < k; i++)
    {
        if (millerTest(d, s, n)==false)
            return false;
    }
    return true;
}


ll pollard_rho(ll n)  //pollard rho implementation
{
    if(n%2==0)
        return 2;

    ll x = rand()%n+1;
    ll c = rand()%n+1;
    ll y = x;
    ll g = 1;

    //fn is f(x) = x*x + c
    while(g==1)
    {
        x = (mulMod(x, x, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        g = gcd(abs_val(x-y),n);
    }
    return g;
}

void factorize(ll n)   //fn to factorize the number
{
    if(n == 1)
        return;

    if(isPrime(n))      //if n is prime,store it
    {
        factors[n]++;
        return;
    }
    ll divisor = pollard_rho(n);   //get a divisor of n
    factorize(divisor);
    factorize(n/divisor);
}

ll expo(ll base, ll pow) {
	ll ans = 1;
	while(pow){
		if(pow & 1) 
			ans = ans * base % MOD;
		base = base * base % MOD;
		pow >>= 1;
	}
	return ans;
}

int main(){
	ll n; cin >> n;
	factorize(n);
	ll n_div=1, sum_div=1, prod_div=1, aux=1;
	for(auto it : factors){
		n_div = n_div * (it.second + 1) % MOD;
		sum_div = sum_div * (expo(it.first, it.second + 1) - 1) % MOD * expo(it.first - 1, MOD - 2) % MOD;
		prod_div = expo(prod_div, it.second + 1) * expo(expo(it.first, (it.second * (it.second + 1) / 2)), aux) % MOD;
		aux = aux * (it.second + 1) % (MOD - 1);
	}
	if(sum_div < 0){
		sum_div += MOD;
	}
	cout << n_div << ' ' << sum_div << ' ' << prod_div << endl;
	return 0;
}

