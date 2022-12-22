#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

// k sorted array means the element that will be present at ith position in sorted array lies at a distance
// of atmost k from ith position in original array
// i.e. sort_arr[i] is one of the elements in [arr[i-k],arr[i+k]]

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
        if (minh.size()>k) {
            cout<<minh.top()<<" ";
            minh.pop();
        }
    }
    while (!minh.empty()) {
        cout<<minh.top()<<" ";
        minh.pop();
    }
    print("");
    return 0;
}