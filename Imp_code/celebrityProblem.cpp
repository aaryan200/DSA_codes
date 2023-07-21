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

int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> s;
    for (int i=0;i<n;i++) s.push(i);
    while (s.size() > 1) {
        int i = s.top(); s.pop(); bool is_i = true;
        int j = s.top(); s.pop(); bool is_j = true;
        if (M[i][j] == 1) {
            // i knows j then j is potential celebrity
            s.push(j);
        }
        else s.push(i);
    }
    if (s.size()) {
        int i = s.top();
        for (int j=0;j<n;j++) {
            if (j!=i and M[j][i] == 0) return -1;
        }
        for (int j=0;j<n;j++) {
            if (M[i][j] != 0) return -1;
        }
        return s.top();
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 3;
    vector<vector<int>> M =  {{0, 1, 0},
            {0, 0, 0}, 
            {0, 1, 0}};
    print(celebrity(M, n));
    return 0;
}