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

int Height(BstNode** root) {
    BstNode* temp=*root;
    if (temp==NULL) return -1;
    int leftH=Height(&(temp->left));
    int rightH=Height(&(temp->right));
    return(max(leftH,rightH)+1);
}

void freeTree(BstNode** root) {
    BstNode* temp=*root;
    if (temp==NULL) return;
    freeTree(&(temp->left));
    freeTree(&(temp->right));
    delete temp;
    return;
}

int main() {
    BstNode* root=NULL;
    Insert(&root,15);
    Insert(&root,10);
    Insert(&root,20);
    Insert(&root,25);
    print(Height(&root));
    return 0;
}