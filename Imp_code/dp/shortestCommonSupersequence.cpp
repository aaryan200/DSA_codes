#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }


void solve() {
    string s,t,out="";
    cin>>s>>t;
    int n=s.length(),m=t.length(),iind=n,jind=m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    while (iind>0 and jind>0) {
        if (s[iind-1]==t[jind-1]) {
            out+=s[iind-1];
            jind--;
            iind--;
        }
        else if (dp[iind-1][jind]>dp[iind][jind-1]) {
            out+=s[iind-1];
            iind--;
        }
        else {
            out+=t[jind-1];
            jind--;
        }
    }
    while (iind>0) {
        out+=s[iind-1];
        iind--;
    }
    while (jind>0) {
        out+=t[jind-1];
        jind--;
    }
    reverse(out.begin(),out.end());
    print(out);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}