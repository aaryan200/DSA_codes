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

class node {
public:
    vector<ll> child;
    node() {
        child={};
    }
};

void addEdge(vector<node>& nodes, ll n1,ll n2) {
    nodes[n1].child.push_back(n2);
    nodes[n2].child.push_back(n1);
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

vector<ll> treeCenter(vector<node>& v, ll n) {
    vector<ll> degree(n,0);
    vector<ll> leaves;
    for (ll i=0;i<n;i++) {
        degree[i] = v[i].child.size();
        if (degree[i]==0 or degree[i]==1) {
            degree[i]=0;
            leaves.push_back(i);
        }
    }
    ll count = leaves.size();
    while (count<n) {
        vector<ll> new_leaves;
        for (auto& leave:leaves) {
            for (auto& child:v[leave].child) {
                degree[child]-=1;
                if (degree[child]==1) new_leaves.push_back(child);
            }
            degree[leave]=0;
        }
        count+=new_leaves.size();
        leaves = new_leaves;
    }
    return leaves;
}

string encode(vector<node>& tree, ll nd, ll parent) {
    if (tree[nd].child.size()==1 and parent!=-1) return "()";
    vector<string> labels;
    for (auto& it:tree[nd].child) {
        if (it!=parent) labels.push_back(encode(tree,it,nd));
    }
    sort(labels.begin(),labels.end());
    string result = "";
    for (auto& it:labels) result=result+it;
    result = "("+result+")";
    return result;
}

bool isIsomorphic(vector<node>& t1, vector<node>& t2, ll n) {
    vector<ll> root1 = treeCenter(t1,n);
    vector<ll> root2 = treeCenter(t2,n);
    string t1_encoding = encode(t1,root1[0],-1);
    for (auto& it:root2) {
        string t2_encoding_temp = encode(t2,it,-1);
        if (t2_encoding_temp==t1_encoding) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,b,ind;
    cin>>n>>m;
    vector<node> v1(n,node());
    vector<node> v2(n,node());
    for (ll i=0;i<m;i++) {
        cin>>a>>b;
        addEdge(v1,a,b);
    }
    for (ll i=0;i<m;i++) {
        cin>>a>>b;
        addEdge(v2,a,b);
    }
    // printGraph(v1);
    // printGraph(v2);
    print(isIsomorphic(v1,v2,n));
    // cout<<endl;
    return 0;
}