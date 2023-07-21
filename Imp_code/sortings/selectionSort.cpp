// swap min(arr[i],..., arr[n-1]) with arr[i]
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
#define issorted(v) is_sorted(v.begin(), v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
#define vi vector<int>
#define vll vector<ll>
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

void selectionSort(vector<ll>& v, int n) {
    for (int i=0;i<n;i++) {
        int j = i; ll temp = i;
        for (j=i+1;j<n;j++) {
            if (v[j] < v[temp]) temp = j;
        }
        swap(v[i], v[temp]);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 5;
    vector<ll> v = {5, 2, 1, 3, 4};
    selectionSort(v, n);
    for (auto it: v) prints(it);
    cout << nl;
    return 0;
}