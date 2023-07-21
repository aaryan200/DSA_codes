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
#define issorted(v) is_sorted(v.begin(), v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > min

class node {
public:
    vector<int> child;
    node() {
        this->child = {};
    }
};

void printGraph(vector<node>& v) {
    ll c=0;
    for (auto& it:v) {
        cout<<c<<" -> ";
        for (auto& it1:it.child) cout<<it1<<" ";
        cout<<endl;
        c++;
    }
    return;
}

void addEdge(vector<node>& nodes, int n1,int n2) {
    nodes[n1].child.push_back(n2);
	nodes[n2].child.push_back(n1);
    return;
}

bool checkCycle(vector<node>& nodes, int i, vector<bool>& visit, int par) {
    visit[i]=true;
    for (auto& j: nodes[i].child) {
        if (j==par) continue;
        if (visit[j]) return true;
        else {
            if (checkCycle(nodes,j,visit, i)) return true;
        }
    }
    return false;
}

bool checkDegree(vector<node>& nodes, int i, int par, vector<bool>& vis) {
    vis[i] = true;
    if (nodes[i].child.size() > 2) return false;
    for (auto& it:nodes[i].child) {
        if (it == par or vis[it]) continue;
        if (!checkDegree(nodes,it, i, vis)) return false;
    }
    return true;
}

void solve(int ite) {
    int n,m;
    cin >> n >> m;
    vector<node> nodes(n, node());
    rep(i,0,m) {
        int n1,n2;
        cin >> n1 >> n2;
        addEdge(nodes,n1-1,n2-1);
    }
    // printe("HERE");
    // printGraph(nodes);
    vector<bool> visit(n,false);
    int ans =0;
    rep(i,0,n) {
        if (!visit[i]) {
            if (checkCycle(nodes,i,visit, -1)) {
                vector<bool> vis(n, false);
                if (checkDegree(nodes, i, -1, vis)) ans++;
            }
        }
    }
    print(ans);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve(it);
    }
    return 0;
}
