#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

void lcsubstr(string s,string t ) {
    int n=s.length(),m=t.length();
    int dp[n+1][m+1],maxl=-1,len=0;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) dp[i][j]=0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i-1]==t[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
                if (dp[i][j]>maxl) maxl=dp[i][j];
            }
            else dp[i][j]=0;
        }
    }
    print(maxl);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    lcsubstr(s,t);
    return 0;
}