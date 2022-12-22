#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

int longestRepeatingSubseq(string s) {
    int n=s.length();
    int dp[n+1][n+1];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) dp[i][j]=0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i!=j and s[i-1]==s[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    print(longestRepeatingSubseq(s));
    return 0;
}