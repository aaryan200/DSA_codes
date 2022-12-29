/*Only for directed acyclic graphs*/

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

void topsortUtil(vector<node>& nodes, vector<bool>& visit, ll ind, vector<ll>& out) {
    visit[ind]=true;
    for (auto& child:nodes[ind].child) {
        if (!visit[child]) topsortUtil(nodes,visit,child,out);
    }
    out.push_back(ind);
    return;
}
// First, insert all children then insert the node, after all are visited, reverse the array.
// Reason being that if node A is a children of node B, then A may also be children of some other remaining nodes, which should be added before A. But if node B is pushed before A, then it will never result in correct topsort. However with the described method, node A will be pushed then B will be pushed and then others will be pushed. After reversing it, nodes will be in correct topsort.
// This method can't detect cycles
vector<ll> topsort(vector<node>& nodes, ll n) {
    vector<ll> out;
    vector<bool> visit(n,false);
    for (ll i=0;i<n;i++) {
        if (!visit[i]) {
            topsortUtil(nodes,visit,i,out);
        }
    }
    reverse(out.begin(),out.end());
    return out;
}

vector<ll> kahnTopsort(vector<node>& nodes, ll n) {
    vector<ll> in_degree(n,0);
    for (ll i=0;i<n;i++) {
        for (auto& it:nodes[i].child) in_degree[it]++;
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
            in_degree[it]-=1; // one dependcy of every neighbor is reduced
            if (in_degree[it]==0) q.push(it);
        }
    }
    // If graph contains cycle, queue will become empty before reaching end of order array.
    if (ind!=n) return vector<ll>();
    return order;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,b;
    cin>>n>>m;
    vector<node> v(n,node());
    for (ll i=0;i<m;i++) {
        cin>>a>>b;
        addEdge(v,a,b);
    }
    vector<ll> top = kahnTopsort(v,n);
    if (top.empty()) print("Graph contains cycle -_-");
    else {
        for (auto& it:top) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}