// arr[0, i-1] is sorted, find the proper position of arr[i] in this and shift elements
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

void insertionSort(vector<ll>& v, int n) {
    for (int i=1;i<n;i++) {
        ll tmp = v[i];
        int j = i-1;
        while (j >= 0 and v[j] > tmp) {
            swap(v[j], v[j+1]);
            j--;
        }
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
    insertionSort(v, n);
    for (auto it: v) prints(it);
    cout << nl;
    return 0;
}