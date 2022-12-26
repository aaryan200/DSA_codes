#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define repi(i,a,b) for (int i=a;i<b;i++)
#define repl(i,a,b) for (ll i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // __builtin_popcount counts the number of set bits (1) in binary of a number
    int integer; ll longlonginteger; long longinteger;
    cin>>integer>>longinteger>>longlonginteger;
    cout<<bpcnt(integer)<<" "<<__builtin_popcountl(longinteger)<<" "<<__builtin_popcountll(longlonginteger);
    return 0;
}