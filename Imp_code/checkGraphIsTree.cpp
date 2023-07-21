// Check if given graph is a tree
// Graph should not have cycles
// It should be fully connected
// In one dfs call, every node should be visited
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "

bool isCycle(vector<vector<int>>& adj, int i, int par, vector<bool>& vis) {
    vis[i] = true;
    for (auto& j: adj[i]) {
        if (j == par) continue;
        if (vis[j]) return true;
        if (isCycle(adj, j, i, vis)) return true;
    }
    return false;
}

bool checkTree(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false);
    int ct = 0;
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            ct++;
            if (isCycle(adj, i, -1, vis)) return false;
        }
    }
    if (ct == 1) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0;i<n-1;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (checkTree(adj, n)) print("YES");
    else print("NO");
    return 0;
}