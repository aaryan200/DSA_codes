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


void solve() {
    ll n,c,tmp;
    cin>>n>>c;
    vector<pair<ll,ll>> a(n,make_pair(0,0));
    vector<pair<ll,ll>> b(n,make_pair(0,0));
    vector<bool> ch(n,false);
    rep(i,0,n) {
        cin>>tmp;
        a[i].first = tmp+i+1;
        a[i].second = i;
        b[i].first = tmp+n-i;
        b[i].second = i;
    }
    sortVec(a);
    sortVec(b);
    ll i=0,aind=0,bind=0,ans=0;
    while (true) {
        if (aind==0 and bind==0) {
            c-=a[aind].first;
            ch[a[aind].second]=true;
            aind++;
        }
        else if ( a[aind]<b[bind] and !ch[a[aind].second]) {
            c-=a[aind].first;
            ch[a[aind].second]=true;
            aind++;
        }
        else if (a[aind]>=b[bind] and !ch[b[bind].second]){
            c-=b[bind].first;
            ch[b[bind].second]=true;
            bind++;
        }
        else if (!ch[a[aind].second]) {
            c-=a[aind].first;
            ch[a[aind].second]=true;
            aind++;
        }
        else if (!ch[b[bind].second]) {
            c-=b[bind].first;
            ch[b[bind].second]=true;
            bind++;
        }
        else if (ch[a[aind].second] and ch[b[bind].second]) {
            aind++;
            bind++;
            continue;
        }
        if (c<0) break;
        ans++;
        // cout<<aind<<" "<<bind<<"\n";
        if (aind==n or bind==n) break;
    }
    print(ans);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}
