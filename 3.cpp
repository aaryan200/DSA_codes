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
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

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

// ll ans(ll h, ll a, ll b) {
//     ll c = max(h-a,(ll)0);
//     ll x;
//     if (c%(a-b)==0) x=c;
//     else x = c+a-b-c%(a-b);
//     if (x>=h) return x/(a-b);
//     return x/(a-b)+1;
// }

int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), i = n-1, j = n-2;
        multiset<int> sc;
        sc.insert(nums[n-1]);
        vector<int> v(n,0);
        v[n-1] = nums[n-1];
        while (true) {
            while (j >= i-k) {
                // cout << i << " " << j << endl;
                v[j] = nums[j] + (*sc.rbegin());
                sc. insert(v[j]);
                j--;
            }
            if ((int)sc.size() > k) sc.erase(sc.find(v[i]));
            if (j==-1) break;
            i--;
        }
        return v[0];
    }

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    cout<<maxResult(v,k)<<nl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}
