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
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

void solve() {
    int n;
    cin>>n;
    vector<int> ans(n,0);
    for (int i=0;i<n;i++) {
        int l,r,k;
        // v[l...r] += k
        cin>>l>>r>>k;
        if (l-1<n) ans[l-1] += k;
        if (r<n) ans[r] -= k;
    }
    for (int i=1;i<n;i++) {
        ans[i] += ans[i-1];
    }
    for (auto& it:ans) prints(it);
    cout<<nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}