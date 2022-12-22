#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

// given n numbers (0 or 1). Converting ith bulb from 0 to 1 result in flipping of all numbers in right.
// Find min number of switches to be pressed.
// i.e. if bulb is 1 go ahead. else if it is 0 => turn it on and flip all elements on right
ll minOp(vector<ll>& a,ll n) {
    ll cost=0;
    for (ll i=0;i<n;i++) {
        if (cost%2==0) {
            if (a[i]==0) cost++;
        }
        else {
            if (a[i]==1) cost++;
        }
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n,0);
    for (ll i=0;i<n;i++) cin>>a[i];
    print(minOp(a,n));
    return 0;
}