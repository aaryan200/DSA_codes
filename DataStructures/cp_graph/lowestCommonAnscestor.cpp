/*Only rooted trees allowed in LCA*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define repi(i,a,b) for (int i=a;i<b;i++)
#define repl(i,a,b) for (ll i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

class sparse_table {
public:
    vector<vector<ll>> actual_values;
    vector<vector<ll>> indexes;
};

/*(i,j)th element is the index of min element in range [j,j+2^i) of array a*/
sparse_table createSparseTable(vector<ll>& a, ll n) {
    ll p = 31 - __builtin_clz(n); // number of row - 1
    vector<vector<ll>> actual_values(p+1,vector<ll>(n,0));
    vector<vector<ll>> indexes(p+1,vector<ll>(n,0));
    // In ith row, the maximum value of column for which range doesn't cross bound is n-2^i
    // Fill the 1st row
    for (ll j=0;j<n;j++) {
        actual_values[0][j]=a[j];
        indexes[0][j]=j;
    }
    for (ll row=1;row<=p;row++) {
        for (ll col=0;col<n;col++) {
            ll left = actual_values[row-1][col], right = actual_values[row-1][col+(1<<(row-1))];
            actual_values[row][col]=min(left,right);
            if (left<right) indexes[row][col]=indexes[row-1][col];
            else indexes[row][col]=indexes[row-1][col+(1<<(row-1))];
        }
    }
    sparse_table t;
    t.actual_values = actual_values;
    t.indexes = indexes;
    return t;
}

/*Given the sparse table and index table, returns the index of element with minimum value in range [l,r]*/
ll minQuery(sparse_table& t, ll l, ll r) {
    ll len = r-l+1, k = msb(len), p = 31 - __builtin_clz(len);
    ll left = t.actual_values[p][l], right = t.actual_values[p][r-k+1];
    if (left<right) return t.indexes[p][l];
    return t.indexes[p][r-k+1];
}

class node {
public:
    vector<ll> child;
    ll parent;
    node() {
        child={};
        parent = -1;
    }
};

void addEdge(vector<node>& nodes, ll n1,ll n2) {
    nodes[n1].child.push_back(n2);
    nodes[n2].parent=n1;
    // nodes[n2].child.push_back(n1);
    // Tree should be rooted in lca
    return;
}

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

void visit(ll nd, ll node_depth, vector<ll>& nodes, vector<ll>& depth, vector<ll>& last, ll& tour_index) {
    nodes[tour_index]=nd;
    depth[tour_index]=node_depth;
    last[nd]=tour_index;
    tour_index++;
    return;
}

void dfs(vector<node>& v, ll nd, ll node_depth, ll& tour_index, vector<ll>& nodes, vector<ll>& depth, vector<ll>& last) {
    visit(nd,node_depth,nodes,depth,last,tour_index);
    for (auto& child:v[nd].child) {
        dfs(v,child,node_depth+1,tour_index,nodes,depth,last);
        visit(nd,node_depth,nodes,depth,last,tour_index);
    }
    return;
}

void setup(vector<node>& v, ll root, ll n, sparse_table& t, vector<ll>& nodes, vector<ll>& last) {
    vector<ll> depth(2*n-1,0);
    ll tour_index=0;
    dfs(v,root,0,tour_index,nodes,depth,last);
    t = createSparseTable(depth,2*n-1);
    return;
}

ll lca(sparse_table& t, ll index1, ll index2, vector<ll>& nodes, vector<ll>& last) {
    ll l = min(last[index1],last[index2]), r = max(last[index1],last[index2]);
    ll i = minQuery(t,l,r);
    return nodes[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,b,ind,root=0;
    cin>>n>>m;
    m = n-1;
    vector<node> v(n,node());
    for (ll i=0;i<m;i++) {
        cin>>a>>b;
        addEdge(v,a,b);
    }
    for (ll i=0;i<n;i++) {
        if (v[i].parent==-1) {
            root = i;
            break;
        }
    }
    vector<ll> nodes(2*n-1,0);
    vector<ll> last(n,0);
    sparse_table t;
    setup(v,root,n,t,nodes,last);
    repi(i,0,5) {
        ll ind1, ind2;
        cin>>ind1>>ind2;
        ll lowestAncestor = lca(t,ind1,ind2,nodes,last);
        cout<<"Lowest common ancestor of "<<ind1<<" and "<<ind2<<" is: "<<lowestAncestor<<endl;
    }
    return 0;
}