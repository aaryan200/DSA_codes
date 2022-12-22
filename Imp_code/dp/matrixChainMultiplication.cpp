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

// Given an array of matrices with given dimensions, find the sequence (way) of multiplying them so that it cost minimum. To multiply two matrices with size axb and bxc, the cost is axbxc

int matrixChainRec(vector<int>& v, int i, int j) {
    if (i>=j) return 0;
    int min_cost = INT_MAX;
    repi(k,i,j) {
        int cost = matrixChainRec(v,i,k)+matrixChainRec(v,k+1,j)+v[i-1]*v[k]*v[j];
        min_cost = min(min_cost,cost);
    }
    return min_cost;
}

int matrixChainRecFunc(vector<int>& v,int n) {
    return matrixChainRec(v,1,n-1);
}

int bottomUpFunc(vector<int>& v, int i, int j, vector<vector<int>>& arr) {
    if (i>=j) return arr[i-1][j-1]=0;
    if (arr[i-1][j-1]!=-1) return arr[i-1][j-1];
    int min_cost = INT_MAX;
    repi(k,i,j) {
        int left_ans, right_ans;
        if (arr[i-1][k-1]!=-1) left_ans = arr[i-1][k-1];
        else left_ans = bottomUpFunc(v,i,k,arr);
        if (arr[k][j-1]!=-1) right_ans = arr[k][j-1];
        else right_ans = bottomUpFunc(v,k+1,j,arr);
        int cost = left_ans+right_ans+v[i-1]*v[k]*v[j];
        min_cost = min(min_cost,cost);
    }
    return arr[i-1][j-1]=min_cost;
}

int matrixChainBottomUp(vector<int>& v,int n) {
    vector<vector<int>> arr(n-1,vector<int>(n-1,-1));
    return bottomUpFunc(v,1,n-1,arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n,0);
    repi(i,0,n) cin>>v[i];
    print(matrixChainBottomUp(v,n));
    return 0;
}