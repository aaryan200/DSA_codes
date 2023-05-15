#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "
#define rep(i,a,b) for (int i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define sortVec(v) sort(v.begin(),v.end())
#define issorted(v) is_sorted(v.begin(), v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

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

const ll mod = 998244353;

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

// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n,ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)% p;
}

ll chckSame(vector<ll> wts) {
    map<ll,ll> mp;
    for (auto& it:wts) mp[it]++;
    if (mp.size()==3) return (ll)1;
    if (mp.size()==1) return (ll)3;
    sortVec(wts);
    if (wts[0] == wts[1]) return (ll)2;
    return (ll)1;
}

void solve(int it) {
    ll n, a, b, c;
    cin >> n;
    vector<vector<ll>> wt(n, vector<ll>());
    rep(i,0,n/3) {
        cin >> a >> b >> c;
        wt[i].push_back(a);
        wt[i].push_back(b);
        wt[i].push_back(c);
    }
    ll ans = nCrModPFermat(n/3, n/6, mod);
    rep(i,0, n/3) {
        ans = (ans * chckSame(wt[i])) % mod;
    }
    print(ans);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve(it);
    }
    return 0;
}
