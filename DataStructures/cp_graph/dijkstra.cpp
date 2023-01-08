/*Only rooted trees allowed in LCA*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "
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

/*Return a pair of arrays consisting of shortest distance of all nodes from node start and previous nodes*/
pair<vector<ll>,vector<ll>> dijkstra(vector<node>& nodes, ll start, ll n) {
    vector<ll> dist(n,LLONG_MAX);
    vector<bool> visit(n,false);
    vector<ll> prev(n,-1);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q; // distance, index
    q.push(make_pair(0,start));
    dist[start] = 0;
    visit[start] = true;
    while (!q.empty()) {
        pair<ll,ll> tp = q.top();
        q.pop();
        visit[tp.second] = true;
        if (dist[tp.second]<tp.first) continue;
        for (auto& it:nodes[tp.second].child) {
            if (!visit[it.first]) {
                ll newDist = dist[tp.second] + it.second;
                if (newDist < dist[it.first]) {
                    dist[it.first] = newDist;
                    prev[it.first] = tp.second;
                    q.push(make_pair(dist[it.first],it.first));
                }
            }
        }
    }
    return make_pair(dist,prev);
}

/*Return shortest distance of node end from node start and array of previous nodes*/
pair<ll,vector<ll>> twoNodeDijkstra(vector<node>& nodes, ll start, ll end, ll n) {
    vector<ll> dist(n,LLONG_MAX);
    vector<bool> visit(n,false);
    vector<ll> prev(n,-1);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q; // distance, index
    q.push(make_pair(0,start));
    dist[start] = 0;
    visit[start] = true;
    while (!q.empty()) {
        pair<ll,ll> tp = q.top();
        q.pop();
        visit[tp.second] = true;
        if (tp.second==end) {
            return make_pair(dist[end],prev);
        }
        if (dist[tp.second]<tp.first) continue;
        for (auto& it:nodes[tp.second].child) {
            if (!visit[it.first]) {
                ll newDist = dist[tp.second] + it.second;
                if (newDist < dist[it.first]) {
                    dist[it.first] = newDist;
                    prev[it.first] = tp.second;
                    q.push(make_pair(dist[it.first],it.first));
                }
            }
        }
    }
    return make_pair(LLONG_MAX,prev);
}

vector<ll> path(pair<vector<ll>,vector<ll>>& vec, ll i) {
    vector<ll> out;
    if (vec.first[i]==LLONG_MAX) return out;
    while (i!=-1) {
        out.push_back(i);
        i = vec.second[i];
    }
    reverse(out.begin(),out.end());
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,b,wt,st,end;
    cin>>n>>m;
    vector<node> v(n,node());
    for (ll i=0;i<m;i++) {
        cin>>a>>b>>wt;
        addEdge(v,a,b,wt);
    }
    cin>>st>>end;
    // pair<vector<ll>,vector<ll>> dij = dijkstra(v,st,n);
    // for (auto& it:dij) cout<<it<<" ";
    // cout<<endl;
    // vector<ll> pt  = path(dij,3);
    // for (auto& it:pt) prints(it);
    pair<ll,vector<ll>> p = twoNodeDijkstra(v,st,end,n);
    print(p.first);
    // for (auto& it:p.second) prints(it);
    // cout<<endl;
    return 0;
}