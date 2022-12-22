#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=3,m=4;
    vector<vector<int>> v(n,vector<int>(m,0));
    for (auto& it:v) {
        for(auto& it1:it) cout<<it1<<" ";
        cout<<endl;
    }
    return 0;
}