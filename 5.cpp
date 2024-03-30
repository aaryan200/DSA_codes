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
#define pll pair<ll,ll>
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
    int n, x;
    cin >> n >> x;
    vi p(n+1);
    int ind_x;
    rep(i,1,n+1) {
        cin >> p[i];
        if (p[i] == x) ind_x = i;
    }
    int l = 1, r = n+1;
    vi v;
    vi b;
    while (r-l != 1) {
        int m = l + (r-l)/2;
        if (p[m] <= x) {
            v.push_back(m);
            b.push_back(0);
            l = m;
        }
        else {
            v.push_back(m);
            b.push_back(1);
            r = m;
        }
    }
    if (l == ind_x) {
        print(0);
        return;
    }
    int ct = count(v.begin(), v.end(), ind_x);
    if (ct) {
        int ind_1 = -1;
        int i =0;
        for (auto& el:v) {
            if (el == ind_x) ind_1 = i;
            i++;
        }
        int ans = -1;
        for (int i=1;i<=n;i++) {
            int ct1 = count(v.begin(), v.end(), i);
            if (ct1 == 0) {
                if (b[ind_1] == 0) {
                    if (p[i] <= x) {
                        ans = i;
                        break;
                    }
                }
                else {
                    if (p[i] > x) {
                        ans = i;
                        break;
                    }
                }
            }
        }
        print(2);
        prints(l);
        print(ind_x);
        prints(ind_x);
        print(ans);
    }
    else {
        print(1);
        prints(l);
        print(ind_x);
    }
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