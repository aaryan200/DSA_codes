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

class store {
	public:
	int hi;
	int bi;
	store(int i1, int i2) {
		hi = i1;
		bi = i2;
	}
};

struct st {
	int hi;
	int bi;
	st (int i1, int i2) {
		hi = i1;
		bi = i2;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<st> maxh;
	// priority_queue<store, vector<store>, greater<store> > minh;
	maxh.push(st(3,4));
	maxh.push(st(4,2));
	maxh.push(st(10,-1));
	maxh.push(st(-1,100));
	st f = maxh.top();
	cout<<f.hi<<" "<<f.bi<<endl;
	return 0;
}