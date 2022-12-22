#include<bits/stdc++.h>
using namespace std;
#define println(x) cout<<x<<endl;

int search_vp(vector<pair<int,int>>& v,int s,int n) {
    int l=0,h=n-1;
    while (h-l>1) {
        int temp=(l+h)/2,f=v[temp].first,se=v[temp].second;
        if (s>=f and s<=se) return temp+1;
        else if (s>se) l=temp;
        else h=temp;
    }
    int f=v[l].first,se=v[l].second;
    if (s>=f and s<=se) return l+1;
    f=v[h].first,se=v[h].second;
    if (s>=f and s<=se) return h+1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,f,l;
    cin>>n;
    vector <int> a(n,0);
    vector <pair<int,int>> v;
    cin>>a[0];
    f=1,l=a[0];
    v.push_back(make_pair(f,l));
    for (int i=1;i<n;i++) {
        cin>>a[i];
        f+=a[i-1];
        l+=a[i];
        v.push_back(make_pair(f,l));
    }
    cin>>m;
    vector <int> q(m,0);
    for (int i=0;i<m;i++) {
        cin>>q[i];
    }
    if (n==1) {
        for (int i=0;i<m;i++) {
            cout<<1<<endl;
        }
        return 0;
    }
    for (int i=0;i<m;i++) {
        cout<<search_vp(v,q[i],n)<<endl;
    }
    return 0;
}