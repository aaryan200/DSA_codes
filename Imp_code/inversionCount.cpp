#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout << x << '\n'
#define printe(x) cout << x << endl
#define prints(x) cout << x << " "
#define rep(i, a, b) for (int i = a; i < b; i++)
#define maxVec(v) *max_element(v.begin(), v.end())
#define minVec(v) *min_element(v.begin(), v.end())
#define sortVec(v) sort(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(), v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
#define vi vector<int>
#define vll vector<ll>
inline ll lsb(ll n)
{
    return n & -n;
}
inline ll msb(ll n) { return (1 << (31 - __builtin_clz(n))); }
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > min

vector<int> bits(ll n) {
    bitset<64> b(n);
    vector<int> v;
    for (int i=0;i<64;i++) {
        v.push_back(b[63-i]);
    }
    return v;
}

ll merge(ll* arr, ll l, ll r, vector<ll>& temp) {
        ll mid = l + (r-l)/2;
        ll i = l, j = mid+1, ind = 0, len = r-l+1, ans = 0;
        while (ind < len) {
            if (i <= mid and j <= r) {
                if (arr[i] <= arr[j]) {
                    temp[ind] = arr[i];
                    i++;
                }
                else {
                    ans += mid - i + 1;
                    temp[ind] = arr[j];
                    j++;
                }
            }
            else if (i <= mid) {
                temp[ind] = arr[i];
                i++;
            }
            else {
                temp[ind] = arr[j];
                j++;
            }
            ind++;
        }
        for (ll k = l; k <= r; k++) {
            arr[k] = temp[k-l];
        }
        return ans;
    }
    ll solve(ll* arr, ll l, ll r, vector<ll>& temp) {
        if (l >= r) return 0;
        ll mid = l + (r-l)/2, ans = 0;
        ans += solve(arr, l, mid, temp);
        ans += solve(arr, mid+1, r, temp);
        ans += merge(arr, l, r, temp);
        // cout << l << " " << r << " " << ans << endl;
        return ans;
    } 
    long long int inversionCount(long long arr[], long long n)
    {
        vector<ll> temp(n);
        return solve(arr, 0, n-1, temp);
    }

void solve(int ite) {
    ll n = 5;
    ll arr[] = {2, 4, 1, 3, 5};
    print(inversionCount(arr, n));
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1, it;
    // cin >> t;
    for (it = 0; it < t; it++) {
        solve(it);
    }
    return 0;
}