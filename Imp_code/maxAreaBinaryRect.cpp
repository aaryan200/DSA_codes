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
const int MAX = 1000;

vector<int> nextSmaller(int* h, int n) {
    vector<int> out;
    stack<int> s;
    out.push_back(n);
    s.push(n-1);
    for (int i=n-2;i>=0;i--) {
        while (!s.empty() and h[s.top()] >= h[i]) {
            s.pop();
        }
        if (s.empty()) out.push_back(n);
        else out.push_back(s.top());
        s.push(i);
    }
    reverse(out.begin(), out.end());
    return out;
}
vector<int> prevSmaller(int* h, int n) {
    vector<int> out;
    out.push_back(-1);
    stack<int> s;
    s.push(0);
    for (int i=1;i<n;i++) {
        while (!s.empty() and h[s.top()] >= h[i]) {
            s.pop();
        }
        if (s.empty()) out.push_back(-1);
        else out.push_back(s.top());
        s.push(i);
    }
    return out;
}
// Similar to max area of histograms
int maxAreaHist(int* h, int n) {
    vector<int> nextSmll, prevSmll;
    nextSmll = nextSmaller(h, n);
    prevSmll = prevSmaller(h, n);
    int ans = INT_MIN;
    for (int i=0;i<n;i++) {
        int l = h[i], b = nextSmll[i] - prevSmll[i] - 1;
        ans = max(ans, l*b);
    }
    return ans;
}
int maxArea(int M[MAX][MAX], int n, int m) {
    int ans = maxAreaHist(M[0], m);
    for (int i=1;i<n;i++) {
        for (int j =0;j<m;j++) {
            if (M[i][j] != 0) M[i][j] += M[i-1][j];
        }
        ans = max(ans, maxAreaHist(M[i], m));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}