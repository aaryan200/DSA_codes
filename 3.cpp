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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<100<<endl;
    for (int i =0;i<100;i++) {
        cout<<2000<<'\n';
        for (int j=0;j<2000;j++) cout<<'a';
        cout<<'\n';
    }
    return 0;
}