#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

int lcsRec(string s,string t,int n,int m) {
    if (n==0 or m==0) return 0;
    else if (s[n-1]==t[m-1]) {
        return 1+lcsRec(s,t,n-1,m-1);
    }
    else {
        return max(lcsRec(s,t,n-1,m),lcsRec(s,t,n,m-1));
    }
}

int lcsTopDown(string s,string t) {
    int n=s.length(),m=t.length();
    int dp[n+1][m+1];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) dp[i][j]=0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n=s.length(),m=s.length();
    print(lcsRec(s,t,n,m));
    print(lcsTopDown(s,t));
    return 0;
}