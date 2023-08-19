// Sum of bitwise OR of all subarrays of an array
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

ll sumBitwiseOR(vector<int>& a, int n) {
    // total subarrays
    ll numSubArrays = (ll)n*(ll(n)+1)/2;
    ll ans = 0;
    // ith bit
    for (int i=0;i<32;i++) {
        // store ith bit of every number in an array
        vector<int> temp;
        for (int j=0;j<n;j++) {
            if (a[j] & (1 << i)) temp.push_back(1);
            else temp.push_back(0);
        }
        int i1 = 0, j1 = 0;
        // Counts the number of subarrays in which ith bit is set
        ll numSubArrays_ith_bit_set = numSubArrays;
        while (true) {
            while (i1 < n and temp[i1] == 1) i1++;
            j1 = i1;
            while (j1 < n and temp[j1] == 0) j1++;
            ll len = j1 - i1;
            numSubArrays_ith_bit_set -= len*(len+1)/2;
            if (j1 >= n) break;
            i1 = j1;
        }
        ans += numSubArrays_ith_bit_set * (1LL << i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 5;
    vector<int> a = {1, 2, 3, 4, 5};
    print(sumBitwiseOR(a, n));
    return 0;
}