#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* getNewNode(int x) {
    BstNode* n1=new BstNode();
    n1->data=x;
    n1->left=NULL;
    n1->right=NULL;
    return n1;
}

void Insert(BstNode** root,int x) {
    if (*root==NULL) *root=getNewNode(x);
    else if (x<= (*root)->data) Insert(&((*root)->left),x);
    else Insert(&((*root)->right),x);
    return;
}

void freeTree(BstNode** root) {
    BstNode* temp=*root;
    if (temp==NULL) return;
    freeTree(&(temp->left));
    freeTree(&(temp->right));
    delete temp;
    return;
}

/*Level order traversal*/
void levelOrder(BstNode* root) {
    if (root==NULL) return;
    queue<BstNode*> q;
    q.push(root);
    while (!q.empty()) {
        BstNode* curr=q.front();
        cout<<curr->data<<" ";
        if (curr->left!=NULL) q.push(curr->left);
        if (curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
    cout<<endl;
    return;
}

/*Preorder traversal*/
void preOrder(BstNode* root) {
    if (root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

/*Inorder traversal*/
vector<int> inOrder(BstNode* root) {
    vector<int> emp={};
    if (root==NULL) return emp;
    vector<int> v=inOrder(root->left);
    // cout<<root->data<<" ";
    v.push_back(root->data);
    vector<int> temp=inOrder(root->right);
    for (auto x:temp) v.push_back(x);
    return v;
}

/*Postorder traversal*/
void postOrder(BstNode* root) {
    if (root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return;
}

int main() {
    BstNode* root=NULL;
    Insert(&root,5);
    Insert(&root,10);
    Insert(&root,7);
    Insert(&root,8);
    Insert(&root,11);
    Insert(&root,4);
    Insert(&root,15);
    Insert(&root,14);
    Insert(&root,12);
    vector<int> v=inOrder(root);
    for (auto x:v) print(x);
    freeTree(&root);
    return 0;
}