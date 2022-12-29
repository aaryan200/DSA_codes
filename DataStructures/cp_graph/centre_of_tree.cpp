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
    nodes[n2].child.push_back(n1);
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

vector<ll> treeCenter(vector<node>& v, ll n) {
    vector<ll> degree(n,0);
    vector<ll> leaves;
    for (ll i=0;i<n;i++) {
        degree[i] = v[i].child.size();
        if (degree[i]==0 or degree[i]==1) {
            degree[i]=0;
            leaves.push_back(i);
        }
    }
    ll count = leaves.size();
    while (count<n) {
        vector<ll> new_leaves;
        for (auto& leave:leaves) {
            for (auto& child:v[leave].child) {
                degree[child]-=1;
                if (degree[child]==1) new_leaves.push_back(child);
            }
            degree[leave]=0;
        }
        count+=new_leaves.size();
        leaves = new_leaves;
    }
    return leaves;
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
    // cin>>ind;
    // printGraph(v);
    // vector<ll> out = dfs(v,ind,n);
    // for (auto& it:out) cout<<it<<" ";
    vector<ll> p = treeCenter(v,n);
    for(auto& it:p) cout<<it<<" ";
    cout<<endl;
    return 0;
}