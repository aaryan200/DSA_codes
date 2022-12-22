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
    unordered_map<int,int> m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
    for (int i=0;i<n;i++) {
        cin>>c;
        m[c]++;
    }
    for (auto& it:m) {
        minh.push(make_pair(it.second,it.first));
        if (minh.size()>k) minh.pop();
    }
    while (!minh.empty()) {
        cout<<minh.top().second<<" ";
        minh.pop();
    }
    print("");
    return 0;
}