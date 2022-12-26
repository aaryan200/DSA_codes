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

void strongly_connectedUtil(vector<node>& nodes, ll ind, vector<ll>& components, ll count) {
    if (components[ind]!=-1) return;
    components[ind]=count;
    for (auto& it:nodes[ind].child) strongly_connectedUtil(nodes,it,components,count);
    return;
}

/*This works for undirected graphs only*/
pair<ll,vector<ll>> strongly_connected(vector<node>& nodes, ll n) {
    ll ct=0;
    vector<ll> components(n,-1);
    for (ll i=0;i<n;i++) {
        if (components[i]==-1) {
            ct++;
            strongly_connectedUtil(nodes,i,components,ct);
        }
    }
    return make_pair(ct,components);
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
    // printGraph(v);
    pair<ll,vector<ll>> pr = strongly_connected(v,n);
    print(pr.first);
    for (auto& it:pr.second) cout<<it<<" ";
    cout<<endl;
    return 0;
}