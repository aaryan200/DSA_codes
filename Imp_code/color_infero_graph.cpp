#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
typedef long long ll;
typedef unsigned long long ull;
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }

class node {
public:
    int parent;
    int color;
    vector<int> child;
    node() {
        child={};
        parent=-1;
        color=0;
    }
};

void addEdge(vector<node>& nodes, int n1,int n2) {
    nodes[n1].child.push_back(n2);
    nodes[n2].parent=n1;
    return;
}

void solve() {
    int n,p,op=0;
    cin>>n;
    vector<node> v(n,node());
    vector<int> color(n,0);
    for (int i=1;i<n;i++) {
        cin>>p;
        addEdge(v,p-1,i);
    }
    for (int i=0;i<n;i++) cin>>color[i];
    queue<int> q;
    v[0].color=color[0];
    q.push(0);
    op++;
    while (!q.empty()) {
        int tp=q.front();
        q.pop();
        if (v[tp].parent!=-1 and v[v[tp].parent].color!=color[tp]) op++;
        v[tp].color=color[tp];
        for (auto& it:v[tp].child) q.push(it);
    }
    print(op);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}