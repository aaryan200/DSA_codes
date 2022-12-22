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

bool isBsUtil(BstNode* root,int minV,int maxV) {
    if (root==NULL) return true;
    if (root->data>minV and root->data<=maxV and isBsUtil(root->left,minV,root->data) and isBsUtil(root->right,root->data,maxV)) return true;
    return false;
}

/*By recursion*/
bool isBST(BstNode* root) {
    return isBsUtil(root,INT_MIN,INT_MAX);
}

/*By inorder traversal*/
bool test_checkInOrder(BstNode* root,int *prev) {
    if (root==NULL) return true;
    if (test_checkInOrder(root->left,prev) and root->data>=*prev) {
        *prev=root->data;
        if (test_checkInOrder(root->right,prev)) return true;
    }
    return false;
}

bool checkInOrder(BstNode* root) {
    int p=INT_MIN;
    return test_checkInOrder(root,&p);
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
    Insert(&root,15);
    Insert(&root,12);
    Insert(&root,-10);
    cout<<checkInOrder(root)<<endl;
    freeTree(&root);
    return 0;
}