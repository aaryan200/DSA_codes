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
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));

class node {
public:
    vector<int> child;
    node() {
        child={};
    }
};

void addEdge(vector<node>& nodes, int n1,int n2) {
    nodes[n1].child.push_back(n2);
	nodes[n2].child.push_back(n1);
    return;
}

void printTree(vector<node>& nodes,int n) {
    for (int i=0;i<n;i++) {
        cout<<i+1<<" -> ";
        for (auto& it:nodes[i].child) cout<<it+1<<" ";
        cout<<endl;
    }
}

const int N=1.0e5+5;
const ll mod=1.0e9+7;
ll dp[N][2];

ll solution(vector<node>& nodes, int ind, int color,int par) {
    if (dp[ind][color]!=-1) return dp[ind][color];
    if (color) {
        ll ct=1;
        for (auto& it:nodes[ind].child) {
			if (it!=par) {
				ll white_temp,black_temp;
				if (dp[it][color]!=-1) white_temp=dp[it][color];
				else white_temp= solution(nodes,it,color,ind);
				if (dp[it][1-color]!=-1) black_temp=dp[it][1-color];
				else black_temp=solution(nodes,it,1-color,ind);
				ct=(ct*(white_temp+black_temp))%mod;
			}
        }
        return dp[ind][color]=ct;
    }
    ll ct=1;
    for (auto& it:nodes[ind].child) {
		if (it!=par) {
			ll white_temp;
			if (dp[it][1-color]!=-1) white_temp=dp[it][1-color];
			else white_temp= solution(nodes,it,1-color,ind);
			ct=(ct*white_temp)%mod;
		}
    }
    return dp[ind][color]=ct;
}
// white = 1, gray = 0, black = -1
void solve() {
    int n,a,b,root=0;
    cin>>n;
    vector<node> v(n,node());
    repi(i,0,n-1) {
        cin>>a>>b;
        addEdge(v,a-1,b-1);
    }
    // printTree(v,n);
    memset(dp,-1,N*2*sizeof(ll));
    ll white=solution(v,root,1,-1);
	ll black=solution(v,root,0,-1);
    print((white+black)%mod);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll it,t=1;
    // cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}