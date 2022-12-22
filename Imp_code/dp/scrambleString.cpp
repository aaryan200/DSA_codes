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

const int N = 30;
int dp[N][N][N][N];

int check(string& s1, string& s2,int i1,int j1, int i2, int j2) {
    if (dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
    if (i1==j1) {
        if (s1[i1]==s2[i2]) return dp[i1][j1][i2][j2]=1;
        else return dp[i1][j1][i2][j2]=0;
    }
    for (int k = i1;k<j1;k++) {
        int part1,part2,part3,part4;
        if (dp[i1][k][i2][i2+k-i1]!=-1) part1 = dp[i1][k][i2][i2+k-i1];
        else part1 = check(s1,s2,i1,k,i2,i2+k-i1);
        if (dp[k+1][j1][i2+k-i1+1][j2]!=-1) part2 = dp[k+1][j1][i2+k-i1+1][j2];
        else part2 = check(s1,s2,k+1,j1,i2+k-i1+1,j2);
        if (part1==1 and part2==1) return dp[i1][j1][i2][j2]=1;
        if (dp[i1][k][j2-(k-i1)][j2]!=-1) part3 = dp[i1][k][j2-(k-i1)][j2];
        else part3 = check(s1,s2,i1,k,j2-(k-i1),j2);
        if (dp[k+1][j1][i2][j2-(k-i1)-1]!=-1) part4 = dp[k+1][j1][i2][j2-(k-i1)-1];
        else part4 = check(s1,s2,k+1,j1,i2,j2-(k-i1)-1);
        if (part3==1 and part4==1) return dp[i1][j1][i2][j2]=1;
    }
    return dp[i1][j1][i2][j2]=0;
}

bool isScramble(string& s1, string& s2) {
    int n = s1.length();
    if (n==1 and s1==s2) return true;
    else if (n==1 and s1!=s2) return false;
    memset(dp,-1,N*N*N*N*sizeof(int));
    if (check(s1,s2,0,n-1,0,n-1)==1) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    print(isScramble(s,t));
    return 0;
}