#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
template <typename dt>
class node{
public:
    dt data;
    vector<ll> conn;
    node(dt dat) {
        data=dat;
        conn={};
    }
};

/*Connects node at 0th index n1 to node at 0th index n2*/
void addEdge(vector<node<ll>>& v,ll n1,ll n2) {
    v[n1].conn.push_back(n2);
    // v[n2].conn.push_back(n1); // for unordered
    return;
}

/*White(1) means node is undiscovered, Gray(0) means node is discovered but some(maybe all) of connected nodes are not yet discovered and Black(-1) means all connected nodes of the node and node itself are discovered
start is starting node
n -> number of nodes*/
vector<ll> bfs(vector<node<ll>>& v,ll start,ll n) {
    vector<ll> out;
    vector<int> color;
    vector<ll> d; // distance of node from start node
    vector<ll> parent; // parent of node
    for (ll i=0;i<n;i++) {
        if (i==start) {
            color.push_back(0);
            d.push_back(0);
        }
        else {
            color.push_back(1);
            d.push_back(LLONG_MAX);
        }
        parent.push_back(-1);
    }
    queue<ll> q;
    q.push(start);
    while (!q.empty()) {
        ll u=q.front();
        q.pop();
        for (auto& it:v[u].conn) {
            if (color[it]==1) {
                color[it]=0;
                parent[it]=u;
                d[it]=d[u]+1;
                q.push(it);
            }
        }
        color[u]=-1;
        out.push_back(u);
    }
    return out;
}

vector<ll> dfs_visit(vector<node<ll>>& v,ll ind,ll n,ll* time,vector<ll>& d,vector<ll>& parent,vector<ll>& f,vector<int>& color) {
    vector<ll> out;
    color[ind]=0;
    (*time)++;
    d[ind]=*time;
    for (auto& it:v[ind].conn) {
        if (color[it]==1) {
            parent[it]=ind;
            out.push_back(it);
            vector<ll> temp=dfs_visit(v,it,n,time,d,parent,f,color);
            out.insert(out.end(),temp.begin(),temp.end());
        }
    }
    color[ind]=-1;
    f[ind]=(*time)+1;
    (*time)++;
    return out;
}

/*d records timestamp when node is discovered and f records timestamp when node is finished
Vertex u has color WHITE(1) before d[u], GRAY(0) between d[u] and f[u] and BLACK(-1) after f[u]*/
vector<ll> dfs(vector<node<ll>>& v,ll n) {
    vector<ll> d(n,0);
    vector<ll> f(n,0);
    vector<ll> out;
    vector<ll> parent(n,-1);
    vector<int> color(n,1);
    ll time=0;
    for (ll i=0;i<n;i++) {
        if (color[i]==1) {
            out.push_back(i);
            vector<ll> temp=dfs_visit(v,i,n,&time,d,parent,f,color);
            out.insert(out.end(),temp.begin(),temp.end());
        }
    }
    return out;
}

void printGraph(vector<node<ll>>& v) {
    ll c=0;
    for (auto& it:v) {
        cout<<c+1<<" -> ";
        for (auto& it1:it.conn) cout<<it1+1<<" ";
        cout<<endl;
        c++;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,u,v1; // number of nodes, edges
    cin>>n>>m;
    vector<node<ll>> v;
    for (ll i=0;i<n;i++) {
        node<ll> n1(i+1);
        v.push_back(n1);
    }
    for (ll i=0;i<m;i++) {
        cin>>u>>v1;
        addEdge(v,u-1,v1-1);
    }
    printGraph(v);
    print("");
    vector<ll> v2=dfs(v,n);
    for (auto& it:v2) cout<<it<<" ";
    print("");
    return 0;
}