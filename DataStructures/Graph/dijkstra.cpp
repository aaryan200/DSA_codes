#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

class node{
public:
    ll data;
    vector<pair<ll,ll>> conn; // index, weight
    node(ll dat) {
        data=dat;
        conn={};
    }
};

/*Connects node at 0th index n1 to node at 0th index n2*/
void addEdge(vector<node>& v,ll n1,ll n2,ll wt) {
    v[n1].conn.push_back(make_pair(n2,wt));
    // v[n2].conn.push_back(n1); // for unordered
    return;
}

void printGraph(vector<node>& v) {
    for (auto& it:v) {
        cout<<it.data-1<<" -> ";
        for (auto& it1:it.conn) cout<<it1.first<<","<<it1.second<<" ";
        cout<<endl;
    }
    return;
}

vector<ll> dijkstra(vector<node>& v, ll n, ll s) {
    vector<bool> visit(n,false);
    vector<ll> dist(n,LLONG_MAX);
    dist[s]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; // dist,index
    pq.push(make_pair(0,s));
    while (!pq.empty()) {
        ll d,ind;
        d=pq.top().first,ind=pq.top().second;
        visit[ind]=true;
        pq.pop();
        for (auto& it:v[ind].conn) {
            if (visit[it.first]) continue;
            ll newDist=dist[ind]+it.second;
            if (newDist<dist[it.first]) {
                dist[it.first]=newDist;
                pq.push(make_pair(newDist,it.first));
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,u,v1,wt; // number of nodes, edges
    cin>>n>>m;
    vector<node> v;
    for (ll i=0;i<n;i++) {
        node n1(i+1);
        v.push_back(n1);
    }
    for (ll i=0;i<m;i++) {
        cin>>u>>v1>>wt;
        addEdge(v,u,v1,wt);
    }
    printGraph(v);
    print("");
    vector<ll> dist=dijkstra(v,n,0);
    for (int i=0;i<n;i++) {
        if (dist[i]==LLONG_MAX) cout<<i<<": Not Reachable"<<endl;
        else cout<<i<<": "<<dist[i]<<endl;
    }
    return 0;
}