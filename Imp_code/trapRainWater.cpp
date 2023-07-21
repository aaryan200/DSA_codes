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

int trap(vector<int>& h) {
    // Contribution of h[i] is
    // Let next bigger/equal height is at j
    // Let maximum element in [i+1, j-1] is h[k]
    // Contribution = (h[i] - h[k])*(j-i-1)
    int n = h.size();
    if (n<=2) return 0;
    // Brute Force:
    // int ans = 0;
    // for (int i=0;i<n-2;i++) {
    //     int maxel = h[i+1];
    //     for (int j=i+2;j<n;j++) {
    //         ans += max(0, (min(h[i], h[j]) - maxel)*(j-i-1));
    //         maxel = max(h[j], maxel);
    //     }
    // }
    // return ans;
    // Optimized:
    // nextBigger, prevBiggerOrEqual
    vector<pair<int,int>> nb, pbe; // v.second is required element and v.first is the maximum
    // element between i and v.second where v is either nb or pbe
    stack<pair<int,int>> s1, s2;
    nb.push_back({h[n-1], n-1});
    s1.push({h[n-1], n-1});
    for (int i=n-2;i>=0;i--) {
        int maxEl = INT_MIN;
        while (!s1.empty() and s1.top().first <= h[i]) {
            maxEl = max(maxEl, s1.top().first);
            s1.pop();
        }
        if (s1.empty()) nb.push_back({h[i], i});
        else nb.push_back({max(maxEl, 0), s1.top().second});
        s1.push({h[i], i});
    }
    reverse(nb.begin(), nb.end());
    pbe.push_back({h[0], 0});
    s2.push({h[0], 0});
    for (int i=1;i<n;i++) {
        int maxEl = INT_MIN;
        while (!s2.empty() and s2.top().first < h[i]) {
            maxEl = max(maxEl, s2.top().first);
            s2.pop();
        }
        if (s2.empty()) pbe.push_back({h[i], i});
        else pbe.push_back({max(maxEl, 0), s2.top().second});
        s2.push({h[i], i});
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        ans += (h[i] - nb[i].first)*(nb[i].second - i - 1) + (h[i]-pbe[i].first)*(i - pbe[i].second - 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> h = {4, 2, 0, 3, 2, 5};
    print(trap(h));
    return 0;
}