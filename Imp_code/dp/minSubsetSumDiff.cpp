#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

ll minSubSumDiff(vector<ll>& v, ll n) {
    ll s=0;
    for (ll i=0;i<n;i++) s+=v[i];
    ll hf=s/2,minn=LLONG_MAX;
    vector<vector<bool>> dp(n+1,vector<bool>(hf+1,false));
    for (ll i=0;i<n+1;i++) {
        for (ll j=0;j<hf+1;j++) {
            if (j==0) dp[i][j]=true;
            else if (i==0) dp[i][j]=false;
            else {
                ll x=j-v[i-1];
                if (x>=0) {
                    dp[i][j]=((dp[i-1][j])or(dp[i-1][x]));
                    if (dp[i][j]) {
                        ll temp=s-2*j;
                        if (temp<minn) minn=temp;
                    }
                }
            }
        }
    }
    return minn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,it;
    // cin>>t;
    for (it=0;it<t;it++) {
        ll n;
        cin>>n;
        vector<ll> v(n,0);
        /*
        1 1
        3 4
        4 5
        5 7
        cap:7
        */
        for (ll i=0;i<n;i++) cin>>v[i];
        print(minSubSumDiff(v,n));
    }
    return 0;
}