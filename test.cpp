#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define repi(i,a,b) for (int i=a;i<b;i++)
#define repl(i,a,b) for (ll i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));

void solve() {
    ll n,m,k,st=0;
    cin>>n>>m>>k;
    vector<ll> a(m,0);
    priority_queue<ll, vector<ll>, greater<ll> > q;
    repl(i,0,m) cin>>a[i];
    if (m<k) {
        print("NO");
        return;
    }
    repl(i,0,m) {
        if (st>=k) {
            st = q.top();
            q.pop();
        }
        // print(st);
        ll temp;
        if ((n-st)%k==0) temp = (n-st)/k;
        else temp = (n-st)/k + 1;
        if (a[i]>temp) {
            print("NO");
            return;
        }
        q.push(st+a[i]*k);
        st++;
        // min_av = min(min_av, st+a[i]*k);
        // st = min_av;
    }
    print("YES");
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}