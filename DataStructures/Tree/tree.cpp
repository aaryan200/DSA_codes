#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
template <typename dt>
class node {
public:
    dt data;
    vector<ll> child;
    node(dt dat) {
        data=dat;
        child={};
    }
};

/*Insert 0th index u2 in child of 0th index node u1*/
void insert(vector<node<ll>>& v,ll u1,ll u2) {
    v[u1].child.push_back(u2);
    return;
}

void printTree(vector<node<ll>>& v) {
    for (auto& it:v) {
        cout<<it.data<<" -> ";
        for (auto& it1:it.child) cout<<it1+1<<" ";
        cout<<endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,u,u1;
    cin>>n;
    vector<node<ll>> v;
    for (ll i=0;i<n;i++) {
        node<ll> v1(i+1);
        v.push_back(v1);
    }
    for (ll i=0;i<n-1;i++) {
        cin>>u>>u1;
        insert(v,u-1,u1-1);
    }
    printTree(v);
    return 0;
}