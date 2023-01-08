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

const int N = 2.0e4+5;
int dp[N];

void solve() {
    int n,m;
    cin>>n>>m;
    int temp = 2*m+2;
    if (n>=m) {
        print(n-m);
        return;
    }
    while (temp>=m) {
        dp[temp]=temp-m;
        temp--;
    }
    int prev = m;
    temp = (m+1)/2;
    while (true) {
        dp[temp]=1+dp[2*temp];
        for (int j=temp+1;j<prev;j++){
            dp[j]=1+min(dp[j-1],dp[2*j]);
        }
        if (temp<=n) break;
        prev = temp;
        temp = (temp+1)/2;
    }
    print(dp[n]);
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