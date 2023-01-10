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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> check(101,0); bool ch=false;
    rep(i,0,n) {
        cin>>a[i];
        if (check[a[i]]>0) ch=true;
        check[a[i]]++;
    }
    if (!ch) {
        sort(a.begin(),a.end(),greater<int>());
        print("YES");
        rep(i,0,n) prints(a[i]);
        cout<<"\n";
        return;
    }
    if (ch and n==2) {

        print("NO");
        return;
    }
    sort(a.begin(),a.end(),greater<int>());
    for (int i=1;i<n-i;i++) {
        swap(a[i],a[n-i]);
    }
    int su=0;bool c=false;
    for (int i=0;i<n;i++) {
        if (a[i]==su) {
            c=true;
            break;
        }
        su+=a[i];
    }
    if (c) {
        print("NO");
    }
    else {
        print("YES");
        rep(i,0,n) prints(a[i]);
        cout<<"\n";
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