#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

// canSum(target,numbers) return a boolean indicating whether or not it is possible to generate the 
// targetSum using numbers from the array.
// An element of array can be used as many times as needed.
// All numbers are non-negative

/*O(n^m) time and O(m) space
n -> array length
m -> target*/
bool canSumRec(ll target,vector<ll>& numbers) {
    if (target==0) return true;
    if (target<0) return false;
    for (auto x:numbers) {
        ll rem=target-x;
        if (canSumRec(rem,numbers)) return true;
    }
    return false;
}

bool canSumFunc(ll target,vector<ll>& numbers,map<ll,bool>& m) {
    if (m.find(target)!=m.end()) return m[target];
    if (target==0) return true;
    if (target<0) return false;
    for (auto x:numbers) {
        ll rem=target-x;
        if (canSumFunc(rem,numbers,m)) {
            m[target]=true;
            return true;
        }
    }
    m[target]=false;
    return false;
}

/*O(m*n) time and O(m) space
n -> array length
m -> target*/
bool canSum(ll target,vector<ll>& numbers) {
    map<ll,bool> m;
    return canSumFunc(target,numbers,m);
}

bool canSumTopDown(ll target,vector<ll>& numbers) {
    vector<bool> dp(target+1,false);
    for (ll i=0;i<=target;i++) {
        if (i==0) dp[i]=true;
        else {
            for (auto& it:numbers) {
                ll x=i-it;
                if (x>=0) {
                    if (dp[x]) {
                        dp[i]=dp[x];
                        break;
                    }
                }
            }
        }
    }
    return dp[target];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n,0);
    for (ll i=0;i<n;i++) cin>>a[i];
    print(canSumTopDown(t,a));
    return 0;
}