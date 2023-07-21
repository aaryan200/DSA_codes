// divide into 2 arrays, sort recursively and merge the 2 sorted arrays
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

void mergeArr(vector<ll>& v, int l, int r, vector<ll>& temp) {
    int mid = l + (r-l)/2;
    int ind = 0, len = r-l+1, i = l, j = mid+1;
    while (ind < len) {
        if (i <= mid and j <= r) {
            if (v[i] <= v[j]) {
                temp[ind] = v[i];
                i++;
            }
            else {
                temp[ind] = v[j];
                j++;
            }
        }
        else if (i <= mid) {
            temp[ind] = v[i];
            i++;
        }
        else  {
            temp[ind] = v[j];
            j++;
        }
        ind++;
    }
    for (int i=l;i<=r;i++) v[i] = temp[i-l];
}

void solve(vector<ll>& v, int l, int r, vector<ll>& temp) {
    if (l >= r) return;
    int mid = l + (r-l)/2;
    solve(v, l, mid, temp);
    solve(v, mid+1, r, temp);
    mergeArr(v, l, r, temp);
}

void mergeSort(vector<ll>& v, int n) {
    vector<ll> temp(n);
    solve(v, 0, n-1, temp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 5;
    vector<ll> v = {5, 2, 1, 3, 4};
    mergeSort(v, n);
    for (auto& it:v) prints(it);
    print("");
    return 0;
}