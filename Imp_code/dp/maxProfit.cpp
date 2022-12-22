#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

ll maxProfitRec(vector<ll>& wt,vector<ll>& val,ll cap,ll n) {
    if (n==0 or cap==0) return 0;
    if (wt[n-1]>cap) return maxProfitRec(wt,val,cap,n-1);
    return max(val[n-1]+maxProfitRec(wt,val,cap-wt[n-1],n-1),maxProfitRec(wt,val,cap,n-1));
}

ll maxProfitTopDown(vector<ll>& wt,vector<ll>& val,ll cap,ll n) {
    vector<vector<ll>> v(n+1,vector<ll>(cap+1,0));
    for (ll i=1;i<n+1;i++) {
        for (ll j=1;j<cap+1;j++) {
            if (wt[i-1]>j) v[i][j]=v[i-1][j];
            else {
                v[i][j]=max(val[i-1]+v[i-1][j-wt[i-1]],v[i-1][j]);
            }
        }
    }
    return v[n][cap];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,it;
    cin>>t;
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
        print(maxProfitRec(wt,val,cap,n));
        print(maxProfitTopDown(wt,val,cap,n));
    }
    return 0;
}