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
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

// class store {
// public:
//     ll index;
//     ll weight;
//     store(ll ind, ll wt) {
//         index = ind;
//         weight = wt;
//     }
// };

class node {
public:
    vector<pair<ll,ll>> child; // index, weight
    node() {
        child={};
    }
};

void addEdge(vector<node>& nodes, ll n1,ll n2, ll wt) {
    nodes[n1].child.push_back(make_pair(n2,wt));
    return;
}

void printGraph(vector<node>& v) {
    ll c=0;
    for (auto& it:v) {
        cout<<c<<" -> ";
        for (auto& it1:it.child) cout<<it1.first<<" ";
        cout<<endl;
        c++;
    }
    return;
}

vector<ll> kahnTopsort(vector<node>& nodes, ll n) {
    vector<ll> in_degree(n,0);
    for (ll i=0;i<n;i++) {
        for (auto& it:nodes[i].child) in_degree[it.first]++;
    }
    queue<ll> q;
    // push all nodes with no dependencies in queue
    for (ll i=0;i<n;i++) {
        if (in_degree[i]==0) q.push(i);
    }
    ll ind=0;
    vector<ll> order(n,0);
    while (!q.empty()) {
        ll at = q.front();
        q.pop();
        order[ind]=at;
        ind++;
        for (auto& it:nodes[at].child) {
            in_degree[it.first]-=1; // one dependcy of every neighbor is reduced
            if (in_degree[it.first]==0) q.push(it.first);
        }
    }
    // If graph contains cycle, queue will become empty before reaching end of order array.
    if (ind!=n) return vector<ll>();
    return order;
}

// The single source shortest path problem can be solved efficiently on a DAG in O(V+E) time.
vector<ll> sssp(vector<node>& nodes, ll n, ll start) {
    vector<ll> topsort = kahnTopsort(nodes,n);
    if (topsort.empty()) return vector<ll>();
    vector<ll> dist(n,LLONG_MAX);
    dist[start]=0;
    // All the nodes before start node in topological ordering are definitely unreachable, if we start from start node.
    for (ll i=0;i<n;i++) {
        ll nodeIndex = topsort[i];
        if (dist[nodeIndex]!=LLONG_MAX) {
            for (auto& it:nodes[nodeIndex].child) {
                ll newDist = dist[nodeIndex]+it.second;
                dist[it.first] = min(dist[it.first],newDist);
            }
        }
    }
    return dist;
}

// To find longest path, multiply weight of edges by -1, find shortest paths, again multiply distance by -1.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,a,b,wt,st;
    cin>>n>>m;
    vector<node> v(n,node());
    for (ll i=0;i<m;i++) {
        cin>>a>>b>>wt;
        addEdge(v,a,b,wt);
    }
    cin>>st;
    vector<ll> dist = sssp(v,n,st);
    cout<<"Min distances of all nodes from "<<st<<endl;
    for (ll i=0;i<n;i++) {
        if (dist[i]==LLONG_MAX) cout<<i<<" : Not reachable"<<endl;
        else cout<<i<<" : "<<dist[i]<<endl;
    }
    return 0;
}