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
    int n,c,k;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> minh;
    for (int i=0;i<n;i++) {
        cin>>c;
        minh.push(c);
        if (minh.size()>k) minh.pop();
    }
    priority_queue<int,vector<int>,greater<int>> temp=minh;
    while (!temp.empty()) {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    print("");
    return 0;
}