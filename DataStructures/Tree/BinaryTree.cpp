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

bool Search(BstNode** root,int x) {
    if (*root==NULL) return false;
    int temp=(*root)->data;
    if (x==temp) return true;
    else if (x<temp) Search(&((*root)->left),x);
    else if (x>temp) Search(&((*root)->right),x);
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
    int k;
    cin>>k;
    if (Search(&root,k)) print("Found");
    else print("Not Found");
    freeTree(&root);
    return 0;
}
