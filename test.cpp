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
const int mod = 1.0e9+7;

void solve() {
    int h,w;
    cin>>h>>w;
    vector<string> v(h,"");
    repi(i,0,h) cin>>v[i];
    ll dp[h+1][w+1];
    memset(dp,-1,(h+1)*(w+1)*sizeof(ll));
    dp[h][w]=1;
    for (int i=h-1;i>=1;i--) {
        if (v[i-1][w-1]=='#') dp[i][w]=0;
        else if (v[i-1][w-1]=='.' and dp[i+1][w]) dp[i][w]=1;
        else dp[i][w]=0;
    }
    for (int j=w-1;j>=1;j--) {
        if (v[h-1][j-1]=='#') dp[h][j]=0;
        else if (v[h-1][j-1]=='.' and dp[h][j+1]) dp[h][j]=1;
        else dp[h][j]=0;
    }
    for (int i=h-1;i>=1;i--) {
        for (int j=w-1;j>=1;j--) {
            if (v[i-1][j-1]=='#') dp[i][j]=0;
            else dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
    print((dp[1][1])%(mod));
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