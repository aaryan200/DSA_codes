#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "
#define rep(i,a,b) for (int i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));

const int N = 1.0e4+5;
int dp[N];

bool solution(vector<int>& a, vector<int>& b, int x, int& n) {
    if (dp[x]!=-1) return dp[x];
    if (x==0) return dp[x]=1;
    rep(i,0,n) {
        if (b[i]>0) {
            int xn = x-a[i];
            b[i]--;
            if (xn>=0 and solution(a,b,xn,n)==1) return dp[x]=1;
            b[i]++;
        }
    }
    return dp[x]=0;
}

void solve() {
    memset(dp,-1,N*sizeof(int));
    int n,x;
    cin>>n>>x;
    vector<int> a(n,0);
    vector<int> b(n,0);
    rep(i,0,n) cin>>a[i]>>b[i];
    if (solution(a,b,x,n)) print("Yes");
    else print("No");
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