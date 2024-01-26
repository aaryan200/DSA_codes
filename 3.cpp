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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n==1) {
        print(0);
        return;
    }
    vi maxInd(n);
    maxInd[n-1] = n;
    int maxI = n-1; char maxV = s[n-1];
    for (int i=n-2;i>=0;i--) {
        maxInd[i] = maxI;
        if (s[i] >= maxV) {
            maxV = s[i]; maxI = i;
        }
    }
    char maxEl = maxVec(s);
    // print(maxEl);
    vector<pair<int,char>> temp;
    int i;
    for (i=0;i<n;i++) {
        if (s[i] == maxEl) break;
    }
    while (i!=n) {
        temp.push_back({i, s[i]});
        i = maxInd[i];
    }
    int m = temp.size();
    int temp1 = 1, tempVal = temp[0].second;
    rep(i,1,m) {
        if (temp[i].second != tempVal) break;
        temp1++;
    }
    // int ans = 0;
    rep(i,0,m) {
        // if (s[n-1] == maxEl) break;
        s[temp[i].first] = temp[m-1-i].second;
        // ans++;
    }
    // print(s);
    if (is_sorted(s.begin(), s.end())) {
        print(m-temp1);
        return;
    }
    print(-1);
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