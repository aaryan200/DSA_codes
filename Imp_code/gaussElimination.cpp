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
// bool sortbysec(const vector<ll>& a, const vector<ll>& b) {
//     return a[1] < b[1];
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
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

const ll mod = 1e6 + 3, k = 11;

void solve(int test_number) {
    ll a[k][k];
    ll b[k];
    for (ll i=0;i<k;i++) {
        cout << "? " << i << endl;
        ll y;
        cin >> y;
        b[i] = y;
        for (ll j=0;j<k;j++) {
            a[i][j] = power(i, j, mod);
        }
    }
    // for (int i=0;i<k;i++) {
    //     for (int j=0;j<k;j++) prints(a[i][j]);
    //     cout << " ";
    //     printe(b[i]);
    // }
    // cout << endl;
    // Gauss elimination
    ll coeffs[k];
    for (ll i=0;i<k;i++) {
        for (ll r=i+1;r<k;r++) {
            ll f = (a[r][i] * modInverse(a[i][i], mod))%mod;
            // ll f = 1;
            for (ll c=i;c<k;c++) {
                ll temp = (f * a[i][c]) % mod;
                a[r][c] = (a[r][c] - temp)%mod;
            }
            b[r] -= f*b[i];
            b[r] %= mod;
        }
    }
    // for (int i=0;i<k;i++) {
    //     for (int j=0;j<k;j++) prints(a[i][j]);
    //     cout << " ";
    //     printe(b[i]);
    // }
    for (ll i=k-1;i>=0;i--) {
        ll su = 0;
        for (ll j=i+1;j<k;j++) {
            su += a[i][j]*coeffs[j];
            su %= mod;
        }
        ll temp = (b[i] - su)%mod;
        ll temp1 = 0;
        temp1 = modInverse(a[i][i], mod);
        coeffs[i] = (temp*temp1)%mod;
    }
    // cout << "here2" << endl;
    // rep(i,0,k) cout << coeffs[i] << " ";
    // cout << endl;
    if (coeffs[0] == 0) {
        cout << "! " << 0 << endl;
        return;
    }
    for (ll x=1;x<mod;x++) {
        ll y = 0;
        for (ll i=0;i<k;i++) {
            ll temp = (coeffs[i] * power(x, i, mod))%mod;
            y += temp;
            y %= mod;
        }
        if (y == 0) {
            cout << "! " << x << endl;
            return;
        }
    }
    cout << "! " << -1 << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests = 1, test;
    // cin >> tests;
    for (test = 1; test <= tests; test++) {
        solve(test);
    }
    return 0;
}