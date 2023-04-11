#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "
#define rep(i,a,b) for (int i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define sortVec(v) sort(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

// Only one cycle in the undirected graph

int findParent(int node, vector<int>& parent) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node], parent); // Path compression
}

// union by rank
void merge(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] == rank[v]) {
        parent[u] = v;
        rank[v]++; // Max height of that tree will be increased by one
    }
    else if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else parent[v] = u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n,0);
    vector<int> rank(n,0);
    rep(i,0,n) parent[i] = i;
    vector<vector<int>> e(m,vector<int>(2,0)); // u, v, weight
    rep(i,0,m) {
        cin >> e[i][0] >> e[i][1];
        e[i][0]--;
        e[i][1]--;
    }
    for (int i=0;i<n;i++) {
        int u = findParent(e[i][0], parent);
        int v = findParent(e[i][1], parent);
        if (u!=v) {
            merge(u, v, parent, rank);
        }
        else {
            print("Edge from "<<e[i][0]+1<<" to "<<e[i][1]+1<<" caused the cycle");
            return 0;
        }
    }
    return 0;
}