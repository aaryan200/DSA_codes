#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

// Return an array consisting of smallest number of elements that adds up to exactly target.
// If no such combination, return null

/*time: O(m*(n^m))
space: O(m*m)*/
vector<ll> bestSumRec(ll target,vector<ll>& numbers) {
    vector<ll> emp;
    vector<ll> nu={-1};
    if (target<0) return nu;
    if (target==0) return emp;
    vector<ll> shortestComb=nu;
    for (auto x:numbers) {
        ll rem= target-x;
        vector<ll> remResult= bestSumRec(rem,numbers);
        if (remResult!=nu) {
            remResult.push_back(x);
            if (shortestComb==nu or remResult.size()<shortestComb.size()) shortestComb=remResult;
        }
    }
    return shortestComb;
}

vector<ll> bestSumFunc(ll target,vector<ll>& numbers,map<ll,vector<ll>>& m) {
    if (m.find(target) !=m.end()) return m[target];
    vector<ll> emp;
    vector<ll> nu={-1};
    if (target<0) return nu;
    if (target==0) return emp;
    vector<ll> shortestComb=nu;
    for (auto x:numbers) {
        ll rem= target-x;
        vector<ll> remResult= bestSumFunc(rem,numbers,m);
        if (remResult!=nu) {
            remResult.push_back(x);
            if (shortestComb==nu or remResult.size()<shortestComb.size()) shortestComb=remResult;
        }
    }
    m[target]=shortestComb;
    return m[target];
}

/*O(n*m*m) time because n*m recursive calls and m lenght array is copied
Space O(m*m) because m keys and m length array stored for each key*/
vector<ll> bestSum(ll target,vector<ll>& numbers) {
    map<ll,vector<ll>> m;
    return bestSumFunc(target,numbers,m);
}

vector<ll> bestSumTopDown(ll target,vector<ll>& numbers) {
    vector<ll> nu={-1};
    vector<vector<ll>> v(target+1,nu);
    for (ll i=0;i<target+1;i++) {
        if (i==0) v[i].clear();
        else {
            vector<ll> shrt=nu;
            for (auto& it:numbers) {
                ll x=i-it;
                if (x>=0) {
                    vector<ll> v1=v[x];
                    if (v1!=nu) {
                        v1.push_back(it);
                        if (shrt==nu or v1.size()<shrt.size()) {
                            shrt.clear(); shrt=v1;
                        }
                    }
                }
            }
            v[i].clear(); v[i]=shrt;
        }
    }
    return v[target];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    cin>>n>>t;
    vector<ll> nu={-1};
    vector<ll> a(n,0);
    for (ll i=0;i<n;i++) cin>>a[i];
    vector<ll> b=bestSumTopDown(t,a);
    if (b!=nu) {
    for (auto x:b) cout<<x<<" ";
    print("");
    return 0;
    }
    print("Not possible");
    return 0;
}