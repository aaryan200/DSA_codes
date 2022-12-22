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

void solve() {
    int n,s=0;
    cin>>n;
    vector<int> a(n,0);
    vector<int> v(n+1,0);
    for (int i=0;i<n;i++) {
        cin>>a[i];
        s+=a[i];
        v[i]=i+1;
    }
    v[n]=n+1;
    if (s==0) {
        for (int i=0;i<n;i++) cout<<v[i]<<" "<<v[i]<<endl;
        print(n);
        return;
    }
    if (s>0) {
        int ct=0;
        for (int i=1;i<n;i++) {
            if (a[i]==1) {
                s-=2;
                v.erase(v.begin()+i-ct);
                ct++;
                i++;
            }
            if (s==0) break;
        }
        if (s==0) {
        int k=v.size();
        print(k-1);
        for (int i=0;i<k-1;i++) {
            cout<<v[i]<<" "<<v[i+1]-1<<endl;
        }
        return;
        }
        print(-1);
        return;
    }
    int ct=0;
    for (int i=1;i<n;i++) {
        if (a[i]==-1) {
            s+=2;
            v.erase(v.begin()+i-ct);
            ct++;
            i++;
        }
        if (s==0) break;
    }
    if (s==0){
    int k=v.size();
    print(k-1);
    for (int i=0;i<k-1;i++) {
        cout<<v[i]<<" "<<v[i+1]-1<<endl;
    }
    return;
    }
    print(-1);
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