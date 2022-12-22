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
    int n,c,cost=0;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> minh;
    for (int i=0;i<n;i++) {
        cin>>c;
        minh.push(c);
    }
    while (minh.size()>1) {
        int c1=minh.top();
        minh.pop();
        int c2=minh.top();
        minh.pop();
        minh.push(c1+c2);
        cost+=c1+c2;
    }
    print(cost);
    return 0;
}