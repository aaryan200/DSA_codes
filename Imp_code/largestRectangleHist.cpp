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

int largestRectangleArea(vector<int>& h) {
    // If next smaller element of h[i] is at index nx
    // If previous smaller element of h[i] is at index pr
    // Then maximum possible width with h[i] as length is nx-pr-1
    int n = h.size();
    stack<pair<int,int>> s1, s2; // number, index
    vector<int> nextSmaller, prevSmaller;
    prevSmaller.push_back(-1);
    s1.push({h[0], 0});
    for (int i=1;i<n;i++) {
        while (!s1.empty() and s1.top().first >= h[i]) {
            s1.pop();
        }
        if (s1.empty()) prevSmaller.push_back(-1);
        else prevSmaller.push_back(s1.top().second);
        s1.push({h[i], i});
    }
    s2.push({h[n-1], n-1});
    nextSmaller.push_back(n);
    for (int i=n-2;i>=0;i--) {
        while (!s2.empty() and s2.top().first >= h[i]) {
            s2.pop();
        }
        if (s2.empty()) nextSmaller.push_back(n);
        else nextSmaller.push_back(s2.top().second);
        s2.push({h[i], i});
    }
    reverse(nextSmaller.begin(), nextSmaller.end());
    int ans = *max_element(h.begin(), h.end());
    for (int i=0;i<n;i++) {
        int temp = h[i]*(nextSmaller[i] - prevSmaller[i] - 1);
        ans = max(ans, temp);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> h = {2, 1, 5, 6, 2, 3};
    print(largestRectangleArea(h));
    return 0;
}