#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

// max heap can find this in nlogk time

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int c;
    priority_queue<int> maxh;
    for (int i=0;i<n;i++) {
        cin>>c;
        maxh.push(c);
        if (maxh.size()>k) maxh.pop();
    }
    print(maxh.top());
    return 0;
}