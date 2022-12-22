#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,ans=0;
    cin>>n;
    while (n&1==0) {
        n=n>>1;
        ans++;
    }
    print(ans);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}