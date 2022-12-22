#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

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

int longestPalindromicSubseq(string s) {
    string s1=s;
    reverse(s.begin(),s.end());
    return lcsTopDown(s,s1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    // int n=s.length();
    // print(lcsRec(s,t,n,m));
    // print(lcsTopDown(s,t));
    print(longestPalindromicSubseq(s));
    return 0;
}