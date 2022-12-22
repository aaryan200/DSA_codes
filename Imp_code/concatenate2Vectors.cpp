#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1={1,2,3};
    vector<int> v2={4,5,6};
    vector<int> v3;
    v3=v1;
    v3.insert(v3.end(),v2.begin(),v2.end()); // 1 2 3 4 5 6
    // v3.insert(v3.begin()+1,v2.begin(),v2.end()); // 1 4 5 6 2 3
    for (auto x:v3) cout<<x<<" ";
    cout<<endl;
    return 0;
}