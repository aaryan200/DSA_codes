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

const int N = 10001, M = 101;
int static dp[M][N];

int eggDropFunc(int e, int f) {
    if (dp[e][f]!=-1) return dp[e][f];
    if (f==0 or f==1) return dp[e][f]=f;
    if (e==1) return dp[e][f]=f;
    int mn = INT_MAX;
    for (int k = 1;k<=f;k++) {
        int bottom_ans, top_ans;
        if (dp[e][f-k]!=-1) top_ans = dp[e][f-k];
        else top_ans = eggDropFunc(e,f-k);
        if (dp[e-1][k-1]!=-1) bottom_ans = dp[e-1][k-1];
        else bottom_ans = eggDropFunc(e-1,k-1);
        int moves = 1+max(bottom_ans,top_ans);
        mn = min(moves,mn);
    }
    return dp[e][f]=mn;
}

/******************************/
// DP with binary search
int eggDrop2(int e, int f) {
    if (dp[e][f]!=-1) return dp[e][f];
    if (f==0 or f==1) return dp[e][f]=f;
    if (e==1) return dp[e][f]=f;
    int mn = INT_MAX;
    int lo=1,hi=f;
    while (hi-lo>1) {
        int k = (hi+lo)/2;
        int bottom_ans, top_ans;
        if (dp[e][f-k]!=-1) top_ans = dp[e][f-k];
        else top_ans = eggDrop2(e,f-k);
        if (dp[e-1][k-1]!=-1) bottom_ans = dp[e-1][k-1];
        else bottom_ans = eggDrop2(e-1,k-1);
        if (top_ans>bottom_ans) lo=k;
        else if (top_ans<bottom_ans) hi=k;
        else {
            hi = k; lo =k;
        }
    }
    for (int k=lo;k<=hi;k++) {
        int ways = 1+max(dp[e-1][k-1],dp[e][f-k]);
        mn = min(mn,ways);
    }
    return dp[e][f]=mn;
}

int superEggDrop(int e, int f) {
    memset(dp,-1,N*M*sizeof(int));
    return eggDrop2(e,f);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e,f;
    cin>>e>>f;
    print(superEggDrop(e,f));
    return 0;
}