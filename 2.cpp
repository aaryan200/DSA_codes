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
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

string lcs_(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];
 
    /* Following steps build L[m+1][n+1] in bottom up
      fashion. Note that L[i][j] contains length of LCS of
      X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // Following code is used to print LCS
    int index = L[m][n];
 
    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character
 
    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1]
                = X[i - 1]; // Put current character in result
            i--;
            j--;
            index--; // reduce values of i, j and index
        }
 
        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
 
    // Print the lcs
    // cout << "LCS of " << X << " and " << Y << " is " << lcs;
    return lcs;
}

string solve1(string s, string l, int m, int n) {
    int il = 0, is = 0;
    string ans = "";
    while (true) {
        bool c = true;
        while (is<m and l[il]!=s[is]) {
            c = false;
            is++;
        }
        if (!c) ans+='*';
        while (il < n and is < m and l[il]==s[is]) {
            ans+=l[il];
            il++;
            is++;
        }
        if (is==m) break;
    }
    return ans;
}

string scsup(string s, string t) {
    string out="";
    int n=s.length(),m=t.length(),iind=n,jind=m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    while (iind>0 and jind>0) {
        if (s[iind-1]==t[jind-1]) {
            out+=s[iind-1];
            jind--;
            iind--;
        }
        else if (dp[iind-1][jind]>dp[iind][jind-1]) {
            out+=s[iind-1];
            iind--;
        }
        else {
            out+=t[jind-1];
            jind--;
        }
    }
    while (iind>0) {
        out+=s[iind-1];
        iind--;
    }
    while (jind>0) {
        out+=t[jind-1];
        jind--;
    }
    reverse(out.begin(),out.end());
    // print(out);
    return out;
}

void solve() {
    string a, b;
    cin>>a>>b;
    int m = a.size(), n = b.size();
    string l = lcs_(a,b,m,n);
    int ls = l.length();
    string s1 = solve1(a,l, m, ls); 
    string s2 = solve1(b,l,n,ls); 
    string sc = scsup(s1, s2);
    int stc = count(sc.begin(),sc.end(),'*');
    if (stc<=sc.length()-stc) {
        print("YES");
        print(sc);
    }
    else print("NO");
    // if (l1>l2) {
    //     if (stc1<=l1-stc1) {
    //         print("YES");
    //         print("here");
    //         print(s1);
    //     }
    //     else print("NO");
    // }
    // else {
    //     if (stc1<=l1-stc1) {
    //         print("YES");
    //         print(s1);
    //     }
    //     else if (stc2<=l2-stc2) {
    //         print("YES");
    //         print(s1);
    //     }
    //     else print("NO");
    // }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}