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

void solve(int ite) {
    FILE* f = fopen("1.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    // cin >> n;
    // cout << n << endl;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        fscanf(f, "%d", &a[i]);
        // cin >> a[i];
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        int minel = INT_MAX, maxel = INT_MIN;
        for (int j=i;j<min(n, i+900);j++) {
            minel = min(minel, a[j]);
            maxel = max(maxel, a[j]);
            if ((minel*maxel)%(j-i+1) == 0) ans++;
        }
    }
    print(ans);
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