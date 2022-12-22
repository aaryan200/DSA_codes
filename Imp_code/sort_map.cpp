// If you print a map by using iterator, it will print in sorted order.

#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int> m;
    int n;
    cin>>n;
    vector <int> v(n,0);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        m[v[i]]=i+1;
    }
    map<int,int> :: iterator iter;
    for (iter=m.begin();iter!=m.end();iter++) cout<<iter->first<<" "<<iter->second<<endl;
    return 0;
}