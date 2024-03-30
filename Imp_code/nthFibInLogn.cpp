// Fibonacci Series using Optimized Method
#include <bits/stdc++.h>
using namespace std;
#define MOD1 (ll)1000000007


void multiply(ll F[2][2], ll M[2][2], ll mod)
{
	ll x = ((F[0][0] * M[0][0])%mod + (F[0][1] * M[1][0])%mod)%mod;
	ll y = ((F[0][0] * M[0][1])%mod + (F[0][1] * M[1][1])%mod)%mod;
	ll z = ((F[1][0] * M[0][0])%mod + (F[1][1] * M[1][0])%mod)%mod;
	ll w = ((F[1][0] * M[0][1])%mod + (F[1][1] * M[1][1])%mod)%mod;
	
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

// Optimized version of power() in method 4
void power(ll F[2][2], ll n, ll mod)
{
	if(n == 0 || n == 1)
	return;
	ll M[2][2] = {{1, 1}, {1, 0}};
	
	power(F, n / 2, mod);
	multiply(F, F, mod);
	
	if (n % 2 != 0)
		multiply(F, M);
}

// Function that returns nth Fibonacci number
ll fib(ll n, ll mod)
{
	ll F[2][2] = {{1, 1}, {1, 0}};
	if (n == 0)
		return 0;
	power(F, n - 1, mod);

	return F[0][0];
}

// Driver code
int main()
{
	ll n;
	cin>>n;
	
	cout << fib(n, MOD1)<<"\n";
	// getchar();
	
	return 0;
}

// This code is contributed by Nidhi_biet
