#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }

ll pow2(ll n) {
    ll out=0;
    while (n%2==0) {
        out++;
        n=n/2;
    }
    return out;
}

ll pow5(ll n) {
    ll out=0;
    while (n%5==0) {
        out++;
        n=n/5;
    }
    return out;
}

void solve(int it) {
    ll n,m,p2,p5,req=1;
    cin>>n>>m;
    if (it==902) {
        cout<<n<<m<<endl;
    }
    if (m==1) {
        print(n);
        return;
    }
    p2=pow2(n); p5=pow5(n);
    ll initz=min(p2,p5);
    for (ll i=0;i<p5;i++) req=req*2;
    for (ll i=0;i<p2;i++) req=req*5;
    if (req>m) {
        ll temp=req,c1=p5,c2=p2;
        while (c2>0 and temp>m) {
            c2--;
            temp=temp/5;
        }
        while (c1>0 and temp>m) {
            c1--;
            temp=temp/2;
        }
        ll maxp=c1+c2,temp2=1;
        for (ll i=0;i<maxp;i++) temp2=temp2*2;
        for (ll po5=1;po5<=maxp;po5++) {
            temp2=temp2*5/2;
            if (temp2>m) break;
        }
        ll req1;
        if (temp2>m) req1=temp2*2/5;
        else req1=temp2;
        print(n*(m-m%req1));
        return;
    }
    if (req<=m) {
        // print(req);
        ll temp=req;
        while (temp<m) temp=temp*10;
        if (temp>m) temp=temp/10;
        // print(temp);
        ll out=m-m%temp;
        print(n*out);
        return;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve(it);
    }
    return 0;
}