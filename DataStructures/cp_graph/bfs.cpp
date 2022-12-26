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

vector<ll> bfs(vector<node>& nodes,ll ind, ll n) {
    vector<ll> out;
    vector<bool> visit(n,false);
    queue<ll> q;
    q.push(ind);
    out.push_back(ind);
    visit[ind]=true;
    while (!q.empty()) {
        ll nd = q.front();
        q.pop();
        for (auto& it:nodes[nd].child) {
            if (!visit[it]) {
                visit[it]=true;
                out.push_back(it);
                q.push(it);
            }
        }
    }
    return out;
}

vector<ll> solve(vector<node>& nodes,ll ind, ll n) {
    vector<ll> prev(n,-1);
    vector<bool> visit(n,false);
    queue<ll> q;
    q.push(ind);
    visit[ind]=true;
    prev[ind]=-1; // special previous to ind
    while (!q.empty()) {
        ll nd = q.front();
        q.pop();
        for (auto& it:nodes[nd].child) {
            if (!visit[it]) {
                visit[it]=true;
                prev[it]=nd;
                q.push(it);
            }
        }
    }
    return prev;
}

vector<ll> reconstructPath(vector<ll> prev, ll s, ll e) {
    vector<ll> out;
    while (prev[e]!=-1) {
        out.push_back(e);
        e = prev[e];
        printe(e);
    }
    if (e!=s) return vector<ll>();
    out.push_back(s);
    reverse(out.begin(),out.end());
    return out;
}

// return shortest path from node s to e
vector<ll> shortestPath(vector<node>& nodes, ll s, ll e, ll n) {
    vector<ll> prev = solve(nodes,s,n);
    // for (auto& it:prev) cout<<it<<" ";
    // cout<<endl;
    return reconstructPath(prev,s,e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,b,s,e;
    cin>>n>>m;
    vector<node> v(n,node());
    for (ll i=0;i<m;i++) {
        cin>>a>>b;
        addEdge(v,a,b);
    }
    cin>>s>>e;
    // printGraph(v);
    vector<ll> out = shortestPath(v,s,e,n);
    for (auto& it:out) cout<<it<<" ";
    cout<<endl;
    return 0;
}