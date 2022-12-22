#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int32_t n,k;
    cin>>n>>k;
    vector<int32_t> v(n,0);
    for (ll i=0;i<n;i++) cin>>v[i];
    vector<int32_t> arr(32,0);
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<32;j++) {
            if (v[i]&(1<<j)) arr[j]++;
        }
    }
    ll ans=0;
    for (ll i=0;i<32;i++) {
        cout<<arr[31-i];
        if (arr[i]%k!=0) ans+=1<<i;
    }
    print("");
    print(ans);
    return 0;
}