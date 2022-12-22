#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

// Count number of subsets of v with sum targ.
ll countSubsets(vector<ll>& v,ll targ, ll n) {
    vector<vector<ll>> dp(n+1,vector<ll>(targ+1,0));
    for (ll i=0;i<n+1;i++) {
        for (ll j=0;j<targ+1;j++) {
            if (j==0) dp[i][j]=1; // null set
            else if (i==0) dp[i][j]=0;
            else if (v[i-1]>j) dp[i][j]=dp[i-1][j];
            else {
                ll x=j-v[i-1];
                dp[i][j]=dp[i-1][j]+dp[i-1][x];
            }
        }
    }
    return dp[n][targ];
}

ll countSubWithDiff(vector<ll>& v,ll n,ll diff) {
    ll s=0;
    for (ll i=0;i<n;i++) s+=v[i];
    if ((s-diff)%2!=0) return 0;
    ll tar=(s-diff)/2;
    return countSubsets(v,tar,n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,it;
    // cin>>t;
    for (it=0;it<t;it++) {
        ll n,diff;
        cin>>n>>diff;
        vector<ll> v(n,0);
        /*
        1 1
        3 4
        4 5
        5 7
        cap:7
        */
        for (ll i=0;i<n;i++) cin>>v[i];
        print(countSubWithDiff(v,n,diff));
    }
    return 0;
}