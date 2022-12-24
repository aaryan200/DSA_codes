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
const int N=21;
const ll mod = 1.0e9+7;
ll dp[N][N][N][N];

ll solution(vector<vector<int>>& a, int i, int j, int k, int l) {
    if (k<i or l<j) return dp[i][j][k][l]=1;
    if (dp[i][j][k][l]!=-1) return dp[i][j][k][l];
    // if (k==i and l==j) {
    //     if (a[i][j]) return dp[i][j][k][l]=1;
    //     else return dp[i][j][k][l]=0;
    // }
    ll ct=0;
    for (int x=i;x<=k;x++) {
        for (int y=j;y<=l;y++) {
            if (a[x][y])
            {
                ll one,two,thre,four;
                if (dp[i][j][x-1][y-1]!=-1) one=dp[i][j][x-1][y-1];
                else one=solution(a,i,j,x-1,y-1);
                if (dp[x+1][y+1][k][l]!=-1) two=dp[x+1][y+1][k][l];
                else two=solution(a,x+1,y+1,k,l);
                if (dp[x+1][j][k][y-1]!=-1) thre= dp[x+1][j][k][y-1];
                else thre=solution(a,x+1,j,k,y-1);
                if (dp[i][j+1][x-1][l]!=-1) four=dp[i][j+1][x-1][l];
                else four=solution(a,i,j+1,x-1,l);
                ct=(ct+one*two+thre*four)%mod;
            }
        }
    }
    return dp[i][j][k][l]=ct;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,0));
    repi(i,0,n) {
        repi(j,0,n) cin>>a[i][j];
    }
    memset(dp,-1,N*N*N*N*sizeof(ll));
    print(solution(a,0,0,n-1,n-1)/n);
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