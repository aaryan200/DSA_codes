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
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)

class node {
public:
    vector<ll> child;
    node() {
        child={};
    }
};

void addEdge(vector<node>& nodes, ll n1,ll n2) {
    nodes[n1].child.push_back(n2);
    return;
}

void printGraph(vector<node>& v) {
    ll c=0;
    for (auto& it:v) {
        cout<<c<<" -> ";
        for (auto& it1:it.child) cout<<it1<<" ";
        cout<<endl;
        c++;
    }
    return;
}

void dfs_util(vector<node>& nodes, vector<ll>& out, vector<ll>& visited, ll nd) {
    if (visited[nd]) return;
    visited[nd]=true;
    out.push_back(nd);
    for (auto& it:nodes[nd].child) dfs_util(nodes,out,visited,it);
    return;
}

vector<ll> dfs(vector<node>& nodes,ll ind, ll n) {
    vector<ll> visited(n,false);
    vector<ll> out;
    dfs_util(nodes,out,visited,ind);
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,b,ind;
    cin>>n>>m;
    vector<node> v(n,node());
    for (ll i=0;i<m;i++) {
        cin>>a>>b;
        addEdge(v,a,b);
    }
    cin>>ind;
    // printGraph(v);
    vector<ll> out = dfs(v,ind,n);
    for (auto& it:out) cout<<it<<" ";
    cout<<endl;
    return 0;
}