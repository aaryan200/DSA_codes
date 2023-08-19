#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout << x << '\n'
#define printe(x) cout << x << endl
#define prints(x) cout << x << " "
#define rep(i, a, b) for (int i = a; i < b; i++)
#define maxVec(v) *max_element(v.begin(), v.end())
#define minVec(v) *min_element(v.begin(), v.end())
#define sortVec(v) sort(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(), v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
#define vi vector<int>
#define vll vector<ll>
inline ll lsb(ll n)
{
    return n & -n;
}
inline ll msb(ll n) { return (1 << (31 - __builtin_clz(n))); }
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353
 
// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > min
 
vector<int> bits(ll n) {
    bitset<64> b(n);
    vector<int> v;
    for (int i=0;i<64;i++) {
        v.push_back(b[63-i]);
    }
    return v;
}
 
vll primes(ll n) {
    vll v(n+1, 0);
    vll temp;
    for (ll i=2;i<=n;i++) {
        if (v[i] == 0) {
            temp.push_back(i);
            ll j = i;
            v[j] = i;
            for (ll j = i*i; j<=n;j+=i) v[j] = i;
        }
    }
    return temp;
}
 
bool check(ll p, vll& v) {
    for (auto& f:v) {
        if ((p%f == 0) and (p!=f)) return false;
    }
    return true;
}
 
// Find out the prime numbers in range [m, n]
// Just find all the prime numbers in range [1, sqrt(n)]
// If any number between m and n is divisible by any prime number in [1, sqrt(n)], then it is not prime number
// Time complexity is (n-m)*(number of primes less than equal to sqrt(n))
void solve(int ite) {
    ll m, n;
    cin >> m >> n;
    ll sqr = sqrt(n) + 0.5;
    vll v = primes(sqr);
    for (ll p = m;p<=n;p++) {
        if (p !=1 and check(p, v)) print(p);
    }
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1, it;
    // cin >> t;
    for (it = 0; it < t; it++) {
        solve(it);
    }
    return 0;
} 