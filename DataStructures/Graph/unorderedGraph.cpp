#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
template <typename dt>
class node{
public:
    dt data;
    ll index;
    node(dt dat) {
        data=dat;
    }
};
template <typename dt>
class unordered_graph
{
public:
    vector<node<dt>> vList;
    vector<vector<node<dt>>> adjList;
    ll vertices;
    unordered_graph (dt firstVertex) {
        node<dt> v(firstVertex);
        v.index=0;
        vList.push_back(v);
        adjList.push_back({});
        vertices=1;
    }
    // ll getIndex(dt data) {
    //     for (ll i=0;i<vertices;i++) {
    //         if (vList[i]==data) return i;
    //     }
    //     return -1;
    // }
    /*Checks if d1 is connected to d2 or not*/
    bool isConn(dt d1,dt d2) {
        ll temp=getIndex(d1);
        if (temp==-1) throw 505;
        for (auto& it:adjList[temp]) if (vList[it]==d2) return true;
        return false;
    }
    /*Return vector which consists of all nodes connected to d1*/
    vector<dt> connNodes(dt d1) {
        vector<dt> v;
        ll temp=getIndex(d1);
        if (temp==-1) throw 505;
        for (auto& it:adjList[temp]) v.push_back(vList[it]);
        return v;
    }

    /*"data" having its connections in "adj" is added*/
    void addNode(dt data,vector<node<dt>> adj) {
        node<dt> v(data);
        v.index=vertices;
        vList.push_back(v);
        vector<node<dt>> v1;
        for (auto& it:adj) {
            ll temp=it.index;
            v1.push_back(temp);
            adjList[temp].push_back(v);
        }
        adjList.push_back(v1);
        vertices++;
        return;
    }

    /*Connects d1 to d2 and d2 to d1*/
    void addEdge(dt d1,dt d2) {
        ll d1i=getIndex(d1),d2i=getIndex(d2);
        if (d1i==-1) {}
        if (!isConn(d1,d2)) {
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
    unordered_graph<string> g("Aaryan");
    g.addNode("Aditya",{"Aaryan"});
    g.addNode("Aayush",{"Aaryan"});
    g.addNode("Darpan",{"Aaryan","Aayush"});
    g.addNode("Abhishek", {"Aditya","Aaryan"});
    g.addEdge("Abhishek","Aayush");
    // g.addEdge("Abhishek","Aaryan");
    // g.disp();
    vector<string> v=g.connNodes("Aarya");
    for (auto& it:v) cout<<it<<" ";
    cout<<endl;
    // print(g.isConn("Aaryan","Aditya"));
    return 0;
}