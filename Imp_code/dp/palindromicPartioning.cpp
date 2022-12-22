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

bool isPalindrome(string& s, int i, int j) {
    while (i<j) {
        if (s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int bottomUpFunc(string& s, int i, int j, vector<vector<int>>& arr) {
    if (i>=j) return arr[i][j]=0;
    if (arr[i][j]!=-1) return arr[i][j];
    if (isPalindrome(s,i,j)) return arr[i][j]=0;
    int min_part = INT_MAX;
    repi(k,i,j) {
        int left_ans, right_ans;
        if (arr[i][k]!=-1) left_ans = arr[i][k];
        else left_ans = bottomUpFunc(s,i,k,arr);
        if (arr[k+1][j]!=-1) right_ans = arr[k+1][j];
        else right_ans = bottomUpFunc(s,k+1,j,arr);
        int cost = left_ans+right_ans+1;
        min_part = min(min_part,cost);
    }
    return arr[i][j]=min_part;
}

int bottomUp(string& s,int n) {
    vector<vector<int>> arr(n,vector<int>(n,-1));
    return bottomUpFunc(s,0,n-1,arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; string s;
    cin>>n>>s;
    print(bottomUp(s,n));
    return 0;
}