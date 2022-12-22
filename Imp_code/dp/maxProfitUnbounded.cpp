#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

// Equvalent to canSum

ll maxProfitTopDown(vector<ll>& wt,vector<ll>& val,ll cap,ll n) {
    vector<vector<ll>> dp(n+1,vector<ll>(cap+1,0));
    for (ll i=0;i<n+1;i++) {
        for (ll j=0;j<cap+1;j++) {
            if (i==0 or j==0) continue;
            ll x=j-wt[i-1];
            if (x<0) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][x]);
        }
    }
    return dp[n][cap];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,it;
    // cin>>t;
    for (it=0;it<t;it++) {
        ll n,cap;
        cin>>n>>cap;
        vector<ll> wt(n,0);
        vector<ll> val(n,0);
        /*
        1 1
        3 4
        4 5
        5 7
        cap:7
        */
        for (ll i=0;i<n;i++) cin>>wt[i]>>val[i];
        // print(maxProfitRec(wt,val,cap,n));
        print(maxProfitTopDown(wt,val,cap,n));
    }
    return 0;
}