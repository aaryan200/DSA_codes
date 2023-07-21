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

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
// bool sortbysec(const vector<ll>& a, const vector<ll>& b) {
//     return a[1] < b[1];
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > minh
// Dynamic allocation
// int *arr = new int[5] { 9, 7, 5, 3, 1 };

vector<int> bits(ll n) {
    bitset<64> b(n);
    vector<int> v;
    for (int i=0;i<64;i++) {
        v.push_back(b[63-i]);
    }
    return v;
}

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

int solve(TreeNode<int>* node, int& ans) {
    if (node == NULL) {
        return 0;
    }
    bool c = true;
    if ((node->left != NULL) and ((node->left)->data >= node->data)) {
        c = false;
    }
    if ((node->right != NULL) and ((node->right)->data <= node->data)) {
        c = false;
    }
    if (c) {
        bool c1 = true;
        int out = 1;
        int temp1 = solve(node->left, ans);
        if (temp1 == -1) c1 = false;
        else out += temp1;
        int temp2 = solve(node->right, ans);
        if (temp2 == -1) c1 = false;
        else out += temp2;
        if (!c1) return -1;
        ans = max(ans, out);
        return out;
    }
    solve(node->left,  ans);
    solve(node->right,  ans);
    return -1;
}

int largestBST(TreeNode<int>* root) 
{
    int ans = 0;
    solve(root, ans);
    return ans;
}

void solve1(int ite) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(1);
    root->right = new TreeNode<int>(4);
    (root->left)->right = new TreeNode<int>(2);
    print(largestBST(root));
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1, it;
    // cin >> t;
    for (it = 0; it < t; it++) {
        solve1(it);
    }
    return 0;
}