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

int findMin(BstNode** root) {
    BstNode* temp=*root;
    if (temp==NULL) {
        cout<<"Tree is Empty"<<endl;
        return -1;
    }
    while (temp->left!=NULL) {
        temp=temp->left;
    }    
    return temp->data;
}

void Delete(BstNode** root,int x) {
    if (*root==NULL) return;
    if (x<((*root)->data)) Delete(&((*root)->left),x);
    else if (x>((*root)->data)) Delete(&((*root)->right),x);
    else {
        // Case 1. No child
        if (((*root)->left)==NULL and ((*root)->right)==NULL) {
            delete *root;
            *root=NULL;
        }
        // Case 2. 1 child
        else if (((*root)->left)==NULL) {
            BstNode* temp=*root;
            *root=(*root)->right;
            delete temp;
        }
        else if ((*root)->right==NULL) {
            BstNode* temp=*root;
            *root=(*root)->left;
            delete temp;
            return;
        }
        // Case 3. 2 child
        else {
        int t=findMin(&((*root)->right));
        (*root)->data=t;
        Delete(&((*root)->right),t);
        }
    }
    return;
} 

/*Inorder traversal*/
void inOrder(BstNode* root) {
    if (root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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
    Insert(&root,15);
    Insert(&root,12);
    Insert(&root,-10);
    inOrder(root);
    cout<<endl;
    Delete(&root,10);
    inOrder(root);
    cout<<endl;
    freeTree(&root);
    return 0;
}