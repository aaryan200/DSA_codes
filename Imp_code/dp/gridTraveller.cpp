#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
// Number of ways to move from top left of a grid to bottom right of mxn grid-> m rows and n columns
// O(2^(m+n)) of recursive
// gridTraveler(m,n)=gridTraveler(n,m)
ll gridTravelerFunc(ll m,ll n,map<pair<ll,ll>,ll>& ma) {
    // char m1=m+48,n1=n+48;
    // string key1="";
    // key1+=m1+','+n1;
    // string key2="";
    // key2+=n1+','+m1;
    // print(key1);
    // print(key2);
    pair<ll,ll> key1=make_pair(m,n);
    pair<ll,ll> key2=make_pair(n,m);
    // print(key1.first);
    // print(key1.second);
    if (ma.find(key1)!=ma.end()) return ma[key1];
    if (ma.find(key2)!=ma.end()) return ma[key2];
    if (m==1 and n==1) return 1;
    if (m==0 or n==0) return 0;
    ma[key1]=gridTravelerFunc(m-1,n,ma)+gridTravelerFunc(m,n-1,ma);
    ma[key2]=ma[key1];
    return ma[key1];
}
ll gridTraveler(ll m,ll n) {
    map<pair<ll,ll>,ll> ma;
    return gridTravelerFunc(m,n,ma);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,n;
    cin>>m>>n;
    print(gridTraveler(m,n));
    return 0;
}