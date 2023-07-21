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

int N = 105;
vector<int> min_div(N, 0); // min_div[i] = minimum prime divisor of i (i >= 2)
// if there is no number less than equal to sqrt(n) which divides n, then n is prime.

void sieve() {
    for (int d=2;d*d<N;d++) {
        if (min_div[d]==0) {
            cout << "Prime: " << d << "\n";
            min_div[d] = d;
            for (int i=d*d;i<N;i+=d) {
                if (min_div[i]==0) {
                    min_div[i] = d;
                }
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        if (min_div[i] == 0) {
            min_div[i] = i;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    print(min_div[50]);
    return 0;
}