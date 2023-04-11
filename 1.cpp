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

bool solve1(vector<ll> a, int n, ll minn) {
    for (int i=0;i<n-1;i++) {
        if (a[i] > minn) {
            a[i+1] -= (a[i]-minn);
            a[i] = minn;
        }
        else if (a[i] < minn) {
            a[i+1] += (minn-a[i]);
            a[i] = minn;
        }
    }
    if (a[n-1] >= a[n-2]) {
        return true;
    }
    return false;
}

bool solve2(vector<ll> a, int n, ll minn) {
    for (int i=n-1;i>0;i--) {
        if (a[i] > minn) {
            a[i-1] -= (a[i]-minn);
            a[i] = minn;
        }
        else if (a[i] < minn) {
            a[i-1] += (minn-a[i]);
            a[i] = minn;
        }
    }
    if (a[0] <= a[1]) {
        return true;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    rep(i,0,n) cin >> a[i];
    ll minn = minVec(a);
    bool ans1 = solve1(a,n,minn);
    bool ans2 = solve2(a,n,minn);
    if (ans1 or ans2) {
        print("YES");
    }
    else {
        print("NO");
    }
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
