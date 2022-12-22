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

// Leaf node is a node connected with only one different node

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int solve(Node** node, int& res) {
    int val = (*node)->data;
    if ((*node)->left != NULL and (*node)->right != NULL) {
        int l = solve(&((*node)->left),res);
        int r = solve(&((*node)->right),res);
        res = max(res, l+r+val);
        return max(l,r)+val;
    }
    else if ((*node)->left == NULL and (*node)->right != NULL) {
        int r = solve(&((*node)->right),res);
        // res = max(res, r+val);
        return r+val;
    }
    else if ((*node)->left != NULL and (*node)->right == NULL) {
        int l = solve(&((*node)->left),res);
        // res = max(res, l+val);
        return l+val;
    }
    return val;
}

// If root has single child, then it will also be counted in path from leaf to leaf
int maxPathSum(Node* root)
{
    // code here
    // Node* temp = root;
    int res = INT_MIN;
    int val = solve(&root, res);
    if (root->left && root->right) return res;
    return max(res,val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}