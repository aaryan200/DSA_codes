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
        for (ll col=0;col<n-(1<<(row-1));col++) {
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

/*It will compare in non-overlapping ranges only*/
ll cascadingMinQuery(sparse_table& t, ll l, ll r) {
    ll min_val = LLONG_MAX, corr_index=0;
    while (l<=r) {
        ll p = 31 - __builtin_clz(r-l+1), temp = 1<<p;
        if (t.actual_values[p][l]<min_val) {
            min_val = t.actual_values[p][l];
            corr_index = t.indexes[p][l];
        }
        l+=temp;
    }
    return corr_index;
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
    sparse_table t;
    t = createSparseTable(a,n);
    // for (auto& it:t.actual_values) {
    //     for (auto& it1:it) cout<<it1<<" ";
    //     cout<<endl;
    // }
    //     cout<<endl;
    // for (auto& it:t.indexes) {
    //     for (auto& it1:it) cout<<it1<<" ";
    //     cout<<endl;
    // }
    repi(i,0,5) {
        ll l,r;
        cin>>l>>r;
        ll ind1 = minQuery(t,l,r), ind2 = cascadingMinQuery(t,l,r);
        cout<<"Index is "<<ind1<<" Value is "<<a[ind1]<<endl;
        cout<<"Index is "<<ind2<<" Value is "<<a[ind2]<<endl;
    }
    return 0;
}