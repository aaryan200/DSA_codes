#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,c,k,x;
    cin>>n>>k>>x;
    priority_queue<pair<int,int>> maxh;
    for (int i=0;i<n;i++) {
        cin>>c;
        maxh.push(make_pair(abs(c-x),c));
        if (maxh.size()>k) maxh.pop();
    }
    while (!maxh.empty()) {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
    cout<<endl;
    return 0;
}