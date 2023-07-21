// Worst case O(n^2)
// Space O(1)
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

int partition(vector<ll>& v, int l, int r) {
    int cnt = 0;
    for (int i=l;i<=r;i++) {
        if (v[i] < v[l]) cnt++;
    }
    int ind = l + cnt;
    swap(v[ind], v[l]);
    int i = l, j = r;
    while (i < ind and j > ind) {
        while (i < ind and v[i] < v[ind]) {
            i++;
        }
        while (j > ind and v[j] >= v[ind]) {
            j--;
        }
        if (i < ind and j > ind) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    return ind;
}

void solve(vector<ll>& v, int l, int r) {
    if (l >= r) return;
    int pivot = partition(v, l, r);
    solve(v, l, pivot - 1);
    solve(v, pivot+1, r);
    return;
}

void quickSort(vector<ll>& v, int n) {
    solve(v, 0, n-1);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 5;
    vector<ll> v = {5, 4, 3, 2, 1};
    quickSort(v, n);
    for (auto& it:v) prints(it);
    print("");
    return 0;
}