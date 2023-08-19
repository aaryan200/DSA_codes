#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define repi(i,a,b) for (int i=a;i<b;i++)
#define repl(i,a,b) for (ll i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)

vector<ll> squares(ll n) {
    vector<ll> out;
    ll sqr = sqrt(2*n) + 0.5;
    for (ll i=0;i<=sqr;i++) out.push_back(i*i);
    return out;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> sqrs = squares(n);
    ll sqrs_size=sqrs.size();
    ll ans = (n * (n + 1)) / 2; // If n is taken int, it will overflow
    vector<ll> a(n,0);
    repl(i,0,n) cin>>a[i];
    vector<ll> xorarr(n,0);
    xorarr[0]=a[0];
    repl(i,1,n) xorarr[i]=xorarr[i-1]^a[i];
    vector<ll> freq(4*n+2,0);
    repl(i,0,n) {
        // print(ans);
        repl(j,0,sqrs_size) {
            ll x = xorarr[i]^sqrs[j];
            ans-=freq[x];
            if (xorarr[i]==sqrs[j]) ans--;
        }
        freq[xorarr[i]]++;
    }
    print(ans);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}