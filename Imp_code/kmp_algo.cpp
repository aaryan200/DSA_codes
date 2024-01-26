#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout << x << '\n'
#define printe(x) cout << x << endl
#define prints(x) cout << x << " "
#define rep(i, a, b) for (int i = a; i < b; i++)
#define maxVec(v) *max_element(v.begin(), v.end())
#define minVec(v) *min_element(v.begin(), v.end())
#define sortVec(v) sort(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(), v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
#define vi vector<int>
#define vll vector<ll>
inline ll lsb(ll n)
{
    return n & -n;
}
inline ll msb(ll n) { return (1 << (31 - __builtin_clz(n))); }
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353
#define MOD3 (ll)1000003

vector<int> computeLpsArr(string& pat) {
    int m = pat.length(), i = 1, len = 0;
    vector<int> lps(m, 0);
    while (i < m) {
        if (pat[len] == pat[i]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len == 0) {
            lps[i] = len;
            i++;
        }
        else {
            len = lps[len-1];
        }
    }
    return lps;
}

vector<int> patternMatch(string& txt, string& pat) {
    int n = txt.length(), m = pat.length();
    vector<int> lps = computeLpsArr(pat);
    vector<int> out;
    int i = 0, j = 0;
    while (n - i >= m - j) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }
        if (j==m) {
            out.push_back(i-j);
            j = lps[j-1];
        }
        else if (i < n and txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
    return out;
}

void solve(int test_number) {
    string txt, pat;
    cin >> txt >> pat;
    vector<int> indices = patternMatch(txt, pat);
    for (auto& i:indices) {
        cout << "Found pattern at index " << i << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests = 1, test;
    // cin >> tests;
    for (test = 1; test <= tests; test++) {
        solve(test);
    }
    return 0;
}