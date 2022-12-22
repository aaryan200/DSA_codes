#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

/*d,pred*/
vector<vector<pair<ll,ll>>> floyd_warshall(vector<vector<ll>>& wt,ll n) {
    vector<vector<pair<ll,ll>>> out(n,vector<pair<ll,ll>>(n,make_pair(0,LLONG_MAX)));
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<n;j++) out[i][j].first=wt[i][j];
    }
    for (ll k=0;k<n;k++) {
        for (ll i=0;i<n;i++) {
            for (ll j=0;j<n;j++) {
                if (out[i][k].first==LLONG_MAX) continue;
                if (out[k][j].first==LLONG_MAX) continue;
                if (out[i][k].first+out[k][j].first<out[i][j].first) {
                    out[i][j].first=out[i][k].first+out[k][j].first;
                    out[i][j].second=k;
                }
            }
        }
    }
    return out;
}

void path(vector<vector<pair<ll,ll>>>& out,ll n,ll i,ll j) {
    if (out[i][j].first==LLONG_MAX) {
        cout<<"Path not possible";
        return;
    }
    if (out[i][j].second==LLONG_MAX) cout<<i<<"->"<<j<<" ";
    else {
        path(out,n,i,out[i][j].second);
        path(out,n,out[i][j].second,j);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,u,v1,wt;
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll>(n,LLONG_MAX));
    for (ll i=0;i<n;i++) v[i][i]=0;
    for (ll i=0;i<m;i++) {
        cin>>u>>v1>>wt;
        v[u][v1]=wt;
    }
    vector<vector<pair<ll,ll>>> out=floyd_warshall(v,n);
    cout<<"  ";
    for (ll i=0;i<n;i++) cout<<i<<" ";
    print("");
    for (ll i=0;i<n;i++) {
        cout<<i<<" ";
        for (ll j=0;j<n;j++) {
            if (out[i][j].first==LLONG_MAX) cout<<"N ";
            else cout<<out[i][j].first<<" ";
        }
        print("");
    }
    ll i,j;
    while (!cin.eof()) {
        cin>>i>>j;
        path(out,n,i,j);
        print("");
    }
    return 0;
}