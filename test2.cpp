#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;
const int N = 3000;
double dp[N][N];

void rec(vector<double>& p, int n, int diff, vector<double>& pas, double prob) {
	if (n==0 and diff>0) pas.push_back(prob);
	else if (n==0) return;
	else {
		rec(p,n-1,1+diff,pas,prob*p[n-1]);
		rec(p,n-1,diff-1,pas,prob*(1-p[n-1]));
	}
}

void solve() {}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<double> p(n,0);
	for (int i=0;i<n;i++) cin>>p[i];
	p.erase(p.begin()+1);
	for (auto& it:p) print(it);
	return 0;
}