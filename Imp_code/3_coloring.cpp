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
// bool sortbysec(const vector<ll>& a, const vector<ll>& b) {
//     return a[1] < b[1];
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > minh
// Dynamic allocation
// int *arr = new int[5] { 9, 7, 5, 3, 1 };
// bitset<64> b(n);

vector<int> out_return(int s, int n, int j, int b) {
    int r, c;
    if (s > n-1) {
        r = s - n + 1 + j;
    }
    else {
        r = j;
    }
    c = s-r;
    return vector<int>({b, r, c});
}

vector<int> fill_this(vector<int>& v, int a, int n) {
    vector<int> out; int s;
    if (a == 1) {
        // Fill a black cell with 2
        for (s=1;s<2*n-1;s+=2) {
            if (v[s] < min(s+1, 2*n-1-s)) {
                out = out_return(s, n, v[s], 2);
                v[s]++;
                return out;
            }
        }
        if (s >= 2*n-1) {
            // If not, fill a white cell with 3
            for (s=0;s<2*n-1;s+=2) {
                if (v[s] < min(s+1, 2*n-1-s)) {
                    out = out_return(s, n, v[s], 3);
                    v[s]++;
                    return out;
                }
            }
        }
    }
    else if (a == 2) {
        // Fill a white cell with 1
        for (s=0;s<2*n-1;s+=2) {
            if (v[s] < min(s+1, 2*n-1-s)) {
                out = out_return(s, n, v[s], 1);
                v[s]++;
                return out;
            }
        }
        if (s >= 2*n-1) {
            // If not, fill a black cell with 3
            for (s=1;s<2*n-1;s+=2) {
                if (v[s] < min(s+1, 2*n-1-s)) {
                    out = out_return(s, n, v[s], 3);
                    v[s]++;
                    return out;
                }
            }
        }
    }
    else {
        // Fill a white cell with 1
        for (s=0;s<2*n-1;s+=2) {
            if (v[s] < min(s+1, 2*n-1-s)) {
                out = out_return(s, n, v[s], 1);
                v[s]++;
                return out;
            }
        }
        if (s >= 2*n-1) {
            // Else fill a black cell with 2
            for (s=1;s<2*n-1;s+=2) {
                if (v[s] < min(s+1, 2*n-1-s)) {
                    out = out_return(s, n, v[s], 2);
                    v[s]++;
                    return out;
                }
            }
        }
    }
    return out;
}

void solve(int test_number) {
    int n;
    cin >> n;
    vector<int> v(2*n-1, 0);
    vi temp;
    for (int q=0;q<n*n;q++) {
        int a;
        cin >> a;
        temp = fill_this(v, a, n);
        cout << temp[0] << " " << temp[1]+1 <<" "<< temp[2]+1 << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests = 1, test;
    // cin >> tests;
    for (test = 1; test <= tests; test++) {
        solve(test);
    }
    return 0;
}