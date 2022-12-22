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
void addEdge(vector<node<string>>& v,ll n1,ll n2) {
    v[n1].conn.push_back(n2);
    // v[n2].conn.push_back(n1); // for unordered
    return;
}

void top_sort_visit(vector<node<string>>& v,ll n,vector<int>& color,ll ind,vector<ll>& out) {
    color[ind]=0;
    for (auto& it:v[ind].conn) {
        if (color[it]==1) {
            top_sort_visit(v,n,color,it,out);
        }
    }
    color[ind]=-1;
    out.push_back(ind);
    return;
}

vector<ll> top_sort(vector<node<string>>& v,ll n) {
    vector<ll> out;
    vector<int> color(n,1);
    for (ll i=0;i<n;i++) {
        if (color[i]==1) {
            top_sort_visit(v,n,color,i,out);
        }
    }
    reverse(out.begin(),out.end());
    return out;
}

vector<ll> dfs_visit(vector<node<string>>& v,ll ind,ll n,ll* time,vector<ll>& d,vector<ll>& parent,vector<ll>& f,vector<int>& color) {
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
vector<ll> dfs(vector<node<string>>& v,ll n) {
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

void printGraph(vector<node<string>>& v) {
    ll c=0;
    for (auto& it:v) {
        c++;
        cout<<it.data<<" -> ";
        for (auto& it1:it.conn) cout<<v[it1].data<<" ";
        cout<<endl;
        c++;
    }
    return;
}

void printTopSort(vector<node<string>>& v,ll n) {
    vector<ll> temp=top_sort(v,n);
    for (auto& it:temp) cout<<v[it].data<<" ";
    cout<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,u,v1; // number of nodes, edges
    cin>>n>>m;
    string s1,s2;
    vector<node<string>> v;
    for (ll i=0;i<n;i++) {
        node<string> n1("watch");
        v.push_back(n1);
    }
    for (ll i=0;i<m;i++) {
        cin>>u>>v1;
        v[u-1].data=s1;
        v[v1-1].data=s2;
        addEdge(v,u-1,v1-1);
    }
    printGraph(v);
    print("");
    printTopSort(v,n);
    vector<ll> dfst=dfs(v,n);
    for (auto& it:dfst) cout<<it<<" ";
    print("");
    return 0;
}