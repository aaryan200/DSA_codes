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
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n,0);
    vector<ll> su(n+1,0);
    repi(i,0,n) cin>>a[i];
    su[0]=0;
    repi(i,1,n+1) su[i]=su[i-1]+a[i-1];
    ll dp[n][n];
    memset(dp,0,n*n*sizeof(ll));
    // Fill table along diagonals
    for (int diff=1;diff<=n-1;diff++) {
        for (int i=0;i<n-diff;i++) {
            int j=i+diff;
            ll mn=LLONG_MAX;
            for (int k=i+1;k<=j;k++) {
                mn=min(mn,dp[i][k-1]+dp[k][j]+su[j+1]-su[i]);
            }
            dp[i][j]=mn;
        }
    }
    print(dp[0][n-1]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}