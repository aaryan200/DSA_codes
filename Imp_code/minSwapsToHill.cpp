/*
You are given an array consisting of n distinct integers. On each move, you can swap any two adjacent values. You want to transform the array into a Hill array. This means that the final array has to be first increasing and then decreasing. It is also allowed that the final array is only increasing or decreasing. What is the minimum number of moves needed?

Input Format

The first input line has an integer n: the size of the array.
The next line has n distinct integers x1,x2,…,xn the contents of the array.
Constraints

The value of n should be between 1 and 2*10^5.
The individual elements xi should be between 1 and 10^9.
*/

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
#define MOD3 (ll)1000003

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
// bool sortbysec(const vector<ll>& a, const vector<ll>& b) {
//     return a[1] < b[1];
// }
// Fill whole array with 0.
// memset(arr, 0, sizeof(arr));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > minh
// Dynamic allocation
// int *arr = new int[5] { 9, 7, 5, 3, 1 };
// bitset<64> b(n);

// Returns x^y mod p
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
  
    x = x % p; // Update x if it is more than or
    // equal to p
  
    while (y > 0) 
    {
      
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
  
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
  
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

int minSwapsHill(vector<int>&nums) {
    int n = nums.size();
    vector<pair<int,int>> v;
    for (int i=0;i<n;i++) {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    int i = 0, j = n-1, ans = 0;
    for (int k=0;k<n;k++) {
        int x = abs(v[k].second - i), y = abs(v[k].second - j);
        if (x <= y) {
            ans += x;
            i++;
        }
        else {
            ans += y;
            j--;
        }
    }
    ans /= 2;
    return ans;
}

void solve(int test_number) {
    int n;
    cin >> n;
    vi v(n);
    rep(i,0,n) cin >> v[i];
    print(minSwapsHill(v));
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