#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "
#define rep(i,a,b) for (int i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define sortVec(v) sort(v.begin(),v.end())
#define issorted(v) is_sorted(v.begin(), v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

/*This function returns a map where every prime factor of n is mapped to number of its occurences in n*/
map<int,int> primeFactorization(int n) {
    map<int,int> m;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            m[i]++;
        }
    }
    if (n != 1) {
        m[n]++;
    }
    return m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 60;
    map<int,int> m = primeFactorization(n);
    for (pair<int,int> p : m) {
        cout << p.first << " " << p.second << nl;
    }
    return 0;
}
