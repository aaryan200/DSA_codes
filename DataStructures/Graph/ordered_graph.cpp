#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;

template <typename dt>
class ordered_graph
{
public:
    vector<dt> vList;
    vector<vector<ll>> adjList; // stores index of connections in vList
    ll vertices;
    ordered_graph (dt firstVertex) {
        vList.push_back(firstVertex);
        adjList.push_back({});
        vertices=1;
    }
    ll getIndex(dt data) {
        for (ll i=0;i<vertices;i++) {
            if (vList[i]==data) return i;
        }
        return -1;
    }
    /*Checks if d1 -> d2 (ordered connected) or not*/
    bool isConn(dt d1,dt d2) {
        ll temp=getIndex(d1);
        for (auto& it:adjList[temp]) if (vList[it]==d2) return true;
        return false;
    }
    /*Return vector which consists of all nodes connected to d1*/
    vector<dt> connNodes(dt d1) {
        vector<dt> v;
        ll temp=getIndex(d1);
        for (auto& it:adjList[temp]) v.push_back(vList[it]);
        return v;
    }

    /*"data" having its connections in "adj" is added, all elements of */
    void addVertex(dt data,vector<dt> adj) {
        vList.push_back(data);
        vector<ll> v;
        for (auto& it:adj) {
            ll temp=getIndex(it);
            v.push_back(temp);
            adjList[temp].push_back(vertices);
        }
        adjList.push_back(v);
        vertices++;
        return;
    }

    /*Connects d1 to d2 and d2 to d1*/
    void addEdge(dt d1,dt d2) {
        if (!isConn(d1,d2)) {
            ll d1i=getIndex(d1),d2i=getIndex(d2);
            adjList[d1i].push_back(d2i);
            adjList[d2i].push_back(d1i);
        }
        return;
    }

    /*Displays the graph*/
    void disp() {
        for (ll i=0;i<vertices;i++) {
            cout<<"Connections of "<<vList[i]<<" are: ";
            for (auto& it:adjList[i]) cout<<vList[it]<<" ";
            cout<<endl;
        }
        return;
    }
};

int main() {
    ordered_graph<string> g("Aaryan");
    g.addVertex("Aditya",{"Aaryan"});
    g.addVertex("Aayush",{"Aaryan"});
    g.addVertex("Darpan",{"Aaryan","Aayush"});
    g.addVertex("Abhishek", {"Aditya","Aaryan"});
    g.addEdge("Abhishek","Aayush");
    // g.addEdge("Abhishek","Aaryan");
    // g.disp();
    vector<string> v=g.connNodes("Aaryan");
    for (auto& it:v) cout<<it<<" ";
    cout<<endl;
    return 0;
}