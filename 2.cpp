#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
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
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > min

void solve() {
    int n,m,c;
    cin>>n>>m;
    vector<pair<vector<int>,int>> v;
    vector<vector<int>> v1;
    rep(i,0,n) {
        vector<pair<int,int>> temp;
        rep(j,0,m) {
            cin>>c;
            temp.push_back({c,j+1});
        }
        sortVec(temp);
        vector<int> t(m);
        rep(j,0,m) t[j] = temp[j].second;
        v.push_back({t,i});
        v1.push_back(t);
    }
    sortVec(v);
    for (int i=0;i<n;i++) {
        cout<<v[i].second<<nl;
        cout<<"v: ";
        for (auto& i:v[i].first) prints(i);
        cout<<nl;
        cout<<"v1: ";
        for (auto& i:v1[i]) prints(i);
        cout<<nl;
    }
    vector<pair<int,int>> b; //index, beauty
    rep(i,0,n) {
        int it = upper_bound(v1.begin(),v1.end(),v[i].first)-v1.begin();
        int bu=0;
        if (it!=0 and it!=n) {
            int b1 = 0, b2 =0;
            rep(j,0,m) {
                if (v[i].first[j]!=v1[it-1][j]) break;
                b1++;
            }
            rep(j,0,m) {
                if (v[i].first[j]!=v1[it][j]) break;
                b2++;
            }
            bu = max(b1,b2);
        }
        else if (it==0) {
            rep(j,0,m) {
                if (v[i].first[j]!=v1[it][j]) break;
                bu++;
            }
        }
        else {
            rep(j,0,m) {
                if (v[i].first[j]!=v1[it-1][j]) break;
                bu++;
            }
        }
        b.push_back({v[i].second,bu});
    }
    // vector<vector<int>> sr(m,vector<int>(n,0));
    // rep(i,0,m) {
    //     rep(j,0,n) sr[i][j] = v[j].first[i];
    // }
    // vector<pair<int,int>> b; //index, beauty
    // rep(i,0,n) {
    //     int bu=0,beg =0,end=n;
    //     rep(j,0,m) {
    //         int lb = lower_bound(sr[j].begin(),sr[j].end(),v[i].first[j]) - sr[j].begin();
    //         int ub = upper_bound(sr[j].begin(),sr[j].end(),v[i].first[j]) - sr[j].begin();
    //         if (lb == n and ub == n) break;
    //         beg = lb; end = ub;
    //         bu++;
    //     }
    //     b.push_back({v[i].second,bu});
    // }
    sortVec(b);
    for (auto& it:b) prints(it.second);
    cout<<nl;
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
