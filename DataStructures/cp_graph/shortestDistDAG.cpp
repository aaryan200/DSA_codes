#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "

vector<int> kahnTopsort(vector<vector<pair<int,int>>>& adj, int n) {
    vector<int> indeg(n, 0);
    for (int i=0;i<n;i++) {
        for (auto& j:adj[i]) {
            indeg[j.first]++;
        }
    }
    queue<int> q;
    for (int i=0;i<n;i++) {
        if (indeg[i] == 0) q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int tp = q.front();
        q.pop();
        ans.push_back(tp);
        for (auto& j:adj[tp]) {
            indeg[j.first]--;
            if (indeg[j.first]==0) q.push(j.first);
        }
    }
    if (ans.size() != n) return vector<int>();
    return ans;
}

// vector consisting of path from s to every other node
// adjaceny consisting of index, weight
vector<int> shortestPathDAG(vector<vector<pair<int,int>>>& adj, int n, int s) {
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    vector<int> tps = kahnTopsort(adj, n);
    for (auto& it:tps) {
        if (dist[it] == INT_MAX) continue;
        for (auto& j:adj[it]) {
            dist[j.first] = min(dist[j.first], dist[it] + j.second);
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}