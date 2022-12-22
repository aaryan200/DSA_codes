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

// all ways to paranthesize a boolean string so that it evaluates to true

pair<int,int> bottomUpFunc(string& s, int i, int j, vector<vector<pair<int,int>>>& arr) {
    if (i>j) return arr[i][j]=make_pair(0,0);
    if (i==j) {
        if (s[i]=='T') return arr[i][j]=make_pair(1,0);
        else return arr[i][j]=make_pair(0,1);
    }
    pair<int,int> def_check = make_pair(-1,-1);
    if (arr[i][j]!=def_check) return arr[i][j];
    int all_ways_true = 0;
    int all_ways_false = 0;
    for (int k = i;k<j; k=k+2) {
        pair<int,int> left_ans, right_ans;
        if (arr[i][k]!=def_check) left_ans = arr[i][k];
        else left_ans = bottomUpFunc(s,i,k,arr);
        if (arr[k+2][j]!=def_check) right_ans = arr[k+2][j];
        else right_ans = bottomUpFunc(s,k+2,j,arr);
        if (s[k+1]=='&') {
            all_ways_true+= left_ans.first*right_ans.first;
            all_ways_false += left_ans.first*right_ans.second+left_ans.second*right_ans.first+left_ans.second*right_ans.second;
        }
        else if (s[k+1]=='|') {
            all_ways_true+= left_ans.first*right_ans.first+left_ans.first*right_ans.second+left_ans.second*right_ans.first;
            all_ways_false += left_ans.second*right_ans.second;
        }
        else {
            all_ways_true+=left_ans.first*right_ans.second+left_ans.second*right_ans.first;
            all_ways_false += left_ans.first*right_ans.first + left_ans.second*right_ans.second;
        }
    }
    return arr[i][j]=make_pair(all_ways_true,all_ways_false);
}

int bottomUp(string& s,int n) {
    vector<vector<pair<int,int>>> arr(n,vector<pair<int,int>>(n,make_pair(-1,-1))); //true, false
    return bottomUpFunc(s,0,n-1,arr).first;
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