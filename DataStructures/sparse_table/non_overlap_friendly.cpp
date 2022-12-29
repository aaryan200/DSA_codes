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

/*(i,j)th element is the sum of all elments in range [j,j+2^i) of array a*/
vector<vector<ll>> createSparseTable(vector<ll>& a, ll n) {
    ll p = 31 - __builtin_clz(n); // number of row - 1
    vector<vector<ll>> sums(p+1,vector<ll>(n,0));
    // In ith row, the maximum value of column for which range doesn't cross bound is n-2^i
    // Fill the 1st row
    for (ll j=0;j<n;j++) sums[0][j]=a[j];
    for (ll row=1;row<=p;row++) {
        for (ll col=0;col<n;col++) {
            ll left = sums[row-1][col], right = sums[row-1][col+(1<<(row-1))];
            sums[row][col]=left+right;
        }
    }
    return sums;
}

/*Given the sparse table, returns the sum of all elements in range [l,r] of original array*/
ll cascadingQuery(vector<vector<ll>>& sparseTable, ll l, ll r) {
    ll su=0;
    while (l<=r) {
        ll p = 31 - __builtin_clz(r-l+1), temp = 1<<p;
        su+=sparseTable[p][l];
        l+=temp;
    }
    return su;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n,0);
    repl(i,0,n) cin>>a[i];
    vector<vector<ll>> t;
    t = createSparseTable(a,n);
    repi(i,0,5) {
        ll l,r;
        cin>>l>>r;
        ll val = cascadingQuery(t,l,r);
        cout<<"Value is "<<val<<endl;
    }
    return 0;
}