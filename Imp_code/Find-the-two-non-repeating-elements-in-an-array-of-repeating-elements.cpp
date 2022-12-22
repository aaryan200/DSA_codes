#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> v(n,0);
    vector<ll> v1;
    vector<ll> v2;
    ll x=0;
    for (ll i=0;i<n;i++) {
        cin>>v[i];
        x=x^v[i];
    }
    // print(x);
    ll least_signif_bit=x&(~(x-1));
    for (ll i=0;i<n;i++) {
        if (v[i]&least_signif_bit) v1.push_back(v[i]);
        else v2.push_back(v[i]);
    }
    ll a=0,b=0;
    for (auto y:v1) {
        a=a^y;
    }
    for (auto y:v2) {
        b=b^y;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}