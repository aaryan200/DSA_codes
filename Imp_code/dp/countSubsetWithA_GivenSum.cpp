#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

// Count number of subsets of v with sum targ.

int countSubsets(vector<int>& v,int targ, int n) {
    vector<vector<int>> dp(n+1,vector<int>(targ+1,0));
    for (int i=0;i<n+1;i++) {
        for (int j=0;j<targ+1;j++) {
            if (j==0) dp[i][j]=1; // null set
            else if (i==0) dp[i][j]=0;
            else if (v[i-1]>j) dp[i][j]=dp[i-1][j];
            else {
                int x=j-v[i-1];
                dp[i][j]=dp[i-1][j]+dp[i-1][x];
            }
        }
    }
    return dp[n][targ];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin>>n>>t;
    vector<int> a(n,0);
    for (int i=0;i<n;i++) cin>>a[i];
    print(countSubsets(a,t,n));
    return 0;
}