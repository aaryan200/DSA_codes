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

vector<int> bits(ll n) {
    bitset<64> b(n);
    vector<int> v;
    for (int i=0;i<64;i++) {
        v.push_back(b[63-i]);
    }
    return v;
}

void solve(int test_number) {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    vll h(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> h[i];
    int i = 0;
    // if (n==1) {
    //     print(0);
    //     return;
    // }
    if (n==1) {
        if (a[0] <= k) {
            print(1);
            // return;
        }
        else print(0);
        return;
    }
    int ans = 0;
    if (minVec(a) <= k) ans = 1;
    while (true) {
        while (i < n-1) {
            if ((h[i] % h[i+1]) != 0) i++;
            else break;
        }
        if (i >= n-1) break;
        ll ctF = 0;
        int j = i;
        while (j < n) {
            ctF += a[j];
            while (ctF > k) {
                ctF -= a[i];
                i++;
            }
            ans = max(ans, j-i+1);
            if (j == n-1) break;
            if ((h[j] % h[j+1]) != 0) break;
            j++;
        }
        i = j;
        if (i >= n-1) break;
    }
    print(ans);
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