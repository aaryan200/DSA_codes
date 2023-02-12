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
#define sortVec(v) sort(v.begin(),v.end())
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



void solve() {
    int n;
    cin>>n;
    vector<int> p(n,0);
    vector<int> ind(n,0);
    rep(i,0,n) {
        cin>>p[i];
        ind[p[i]-1]=i;
    }
    if (n==1) {
        print(0);
        return;
    }
    int ans = 0;
    if (n%2) {
        int i=n/2-1,j=n/2+1;
        if (ind[n/2]==n/2) {
            while (i>=0 and j<n and ans == 0) {
                if (!(ind[i]<ind[j] and ind[i]==i and ind[j]==j)) ans++;
                i--;
                j++;
            }
            while (i>=0 and j<n) {
                if (!(ind[i]<ind[j])) ans++;
                i--;
                j++;
            }
        }
        else ans = n/2;
        print(ans);
    }
    else {
        int i=n/2-1,j=n/2;
        while (i>=0 and j<n and ans == 0) {
            if (!(ind[i]<ind[j] and ind[i]==i and ind[j]==j)) ans++;
            i--;
            j++;
        }
        while (i>=0 and j<n) {
            if (!(ind[i]<ind[j])) ans++;
            i--;
            j++;
        }
        print(ans);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}