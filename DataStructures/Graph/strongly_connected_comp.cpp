#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

class node{
public:
    ll data;
    vector<ll> conn;
    node(ll dat) {
        data=dat;
        conn={};
    }
};

/*Connects node at 0th index n1 to node at 0th index n2*/
void addEdge(vector<node>& v,ll n1,ll n2) {
    v[n1].conn.push_back(n2);
    // v[n2].conn.push_back(n1); // for unordered
    return;
}

void printGraph(vector<node>& v) {
    for (auto& it:v) {
        cout<<it.data<<" -> ";
        for (auto& it1:it.conn) cout<<it1+1<<" ";
        cout<<endl;
    }
    return;
}

void top_sort_visit(vector<node>& v,ll n,vector<int>& color,ll ind,vector<ll>& out) {
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

vector<ll> top_sort(vector<node>& v,ll n) {
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

void dfs_visit(vector<node>& v,ll ind,vector<ll>& dfsTree,vector<int>& color) {
    color[ind]=0;
    for (auto& it:v[ind].conn) {
        if (color[it]==1) {
            dfsTree.push_back(it);
            dfs_visit(v,it,dfsTree,color);
        }
    }
    color[ind]=-1;
    return;
}

vector<vector<ll>> strongly_connected(vector<node>& v,ll n) {
    vector<vector<ll>> out;
    vector<ll> topsort= top_sort(v,n);
    vector<node> v1;
    for (ll i=0;i<n;i++) {
        node n1(i+1);
        v1.push_back(n1);
    }
    for (int i=0;i<n;i++) {
        for (auto& it:v[i].conn) v1[it].conn.push_back(i);
    }
    vector<int> color(n,1);
    for (auto& it:topsort) {
        if (color[it]==1) {
            vector<ll> temp;
            temp.push_back(it);
            dfs_visit(v1,it,temp,color);
            out.push_back(temp);
        }
    }
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,u,v1; // number of nodes, edges
    cin>>n>>m;
    vector<node> v;
    for (ll i=0;i<n;i++) {
        node n1(i+1);
        v.push_back(n1);
    }
    for (ll i=0;i<m;i++) {
        cin>>u>>v1;
        addEdge(v,u-1,v1-1);
    }
    printGraph(v);
    print("");
    vector<vector<ll>> strconn=strongly_connected(v,n);
    // print(strconn.size());
    for (auto& it:strconn) {
        for (auto& it1:it) {
            cout<<it1+1<<" ";
        }
        print("");
    }
    return 0;
}