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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode** node, int& res) {
    if ((*node)==NULL) return 0;
    int l = solve(&((*node)->left),res);
    int r = solve(&((*node)->right),res);
    int val = ((*node)->val);
    int temp = max(l,r)+val;
    int ans = val+l+r;
    res = max(max(max(temp,ans),val),res);
    return max(temp,val);
}
int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    solve(&root,res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}