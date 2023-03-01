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
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > minh;

void solve() {
    string a, b;
    cin>>a>>b;
    int m = a.size(), n = b.size(), i= 0, j=0;
    string ans = "";
    if (m>n) {
        swap(a,b);
        swap(m,n);
    }
    while (true) {
        bool c= true;
        while (i<m and j<n and a[i]!=b[j]) {
            j++;
        }
        if (!c) ans += '*';
        while (i< m and j<n and a[i]==b[j]) {
            ans += a[i];
            i++;
            j++;
        }
        if (j==n or i==m) break;
    }
    if (j!=n) ans+='*';
    int stc = count(ans.begin(),ans.end(),'*');
    if (stc<=ans.length()-stc) {
        print("YES");
        print(ans);
    }
    else print("NO");
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}
