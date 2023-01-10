#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "
#define rep(i,a,b) for (int i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));

void solve() {
    int n;
	cin>>n;
	int i=1,j=n*n;
	bool ct=true;
	if (n%2) {
	for (int r=0;r<n;r++) {
		for (int c=0;c<n;c++) {
			if (ct) {
				prints(i);
				i++;
				ct=false;
			}
			else {
				prints(j);
				j--;
				ct=true;
			}
		}
		cout<<"\n";
	}
	}
	else {
		for (int r=0;r<n;r++) {
		for (int c=0;c<n;c++) {
			if (ct) {
				prints(i);
				i++;
				ct=false;
			}
			else {
				prints(j);
				j--;
				ct=true;
			}
		}
		ct=!(ct);
		cout<<"\n";
	}
	}
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}