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
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
inline ll lsb(ll n)
{
    return n & -n;
}
inline ll msb(ll n) { return (1 << (31 - __builtin_clz(n))); }
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353
#define MOD3 (ll)1000003

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
// bool sortbysec(const vector<ll>& a, const vector<ll>& b) {
//     return a[1] < b[1];
// }
// Fill whole array with 0.
// memset(arr, 0, sizeof(arr));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > minh
// Dynamic allocation
// int *arr = new int[5] { 9, 7, 5, 3, 1 };
// bitset<64> b(n);

// Returns x^y mod p
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
  
    x = x % p; // Update x if it is more than or
    // equal to p
  
    while (y > 0) 
    {
      
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
  
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
  
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

void solve(int test_number) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll bm3 = b%3;
    if (bm3 != 0 and c < 3-bm3) {
        print(-1);
        return;
    }
    ll by3 = (b+c)/3;
    ll md = (b+c)%3;
    if (md != 0) {
        print(a+by3+1);
    }
    else print(a+by3);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests = 1, test;
    cin >> tests;
    for (test = 1; test <= tests; test++) {
        solve(test);
    }
    return 0;
}