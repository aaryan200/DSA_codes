#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }

class node {
public:
    vector<int> child;
    node() {
        child={};
    }
};

void addEdge(vector<node>& nodes, int n1,int n2) {
    nodes[n1].child.push_back(n2);
    return;
}

int height(vector<node>& nodes, int i) {
    if (nodes[i].child.empty()) return 1;
    int maxh=-1;
    for (auto& it:nodes[i].child) maxh=max(maxh,height(nodes,it));
    return 1+maxh;
}

void solve() {
    int n,p,maxh=-1;
    cin>>n;
    vector<node> nodes(n,node());
    vector<int> tops;
    for (int i=0;i<n;i++) {
        cin>>p;
        if (p==-1) tops.push_back(i);
        else addEdge(nodes,p-1,i);
    }
    for (auto& it:tops) maxh=max(maxh,height(nodes,it));
    print(maxh);
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