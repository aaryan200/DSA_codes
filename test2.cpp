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
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > minh;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n==0) return true;
        int sz=flowerbed.size();
        if (sz==1) {
            if (flowerbed[0]) return false;
            return true;
        }
        vector<bool> ch(sz,true);
        for (int i=0;i<sz;i++) {
            if (flowerbed[i]) {
                ch[i] = false;
            }
            else ch[i] = true;
        }
        for (int i=0;i<sz;i++) {
            if (i == 0 and ch[i] and ch[i+1]) {
                n--;
                ch[i] = false;
            }
            else if (i == sz-1 and ch[i] and ch[i-1]) {
                n--;
                ch[i] = false;
            }
            else if (ch[i] and ch[i-1] and ch[i+1]) {
                n--;
                ch[i] = false;
            }
        }
        if (n== 0) return true;
        return false;
    }

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    rep(i,0,n) cin>>a[i];
    print(canPlaceFlowers(a,k));
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}