#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
// 0th digit is ones, 1st digit is ones...
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    for (ll i=0;i<k;i++) n=n/10;
    print(n%10);
    return 0;
}