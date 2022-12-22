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

BstNode* Find(BstNode** root,int x) {
    if ((*root)==NULL) return NULL;
    if ((*root)->data==x) return *root;
    else if ((*root)->data<x) return Find(&((*root)->right),x);
    return Find(&((*root)->left),x);
}

BstNode* getSuccessor(BstNode** root,int x) {
    BstNode* curr=Find(root,x);
    if (curr==NULL) return NULL;
    if (curr->right!=NULL) {
        BstNode* temp=curr->right;
        while (temp->left!=NULL) temp=temp->left;
        return temp;
    }
    else {
        BstNode* succ=NULL;
        BstNode* ansc=*root;
        while (ansc!=curr) {
            if (curr->data<ansc->data) {
                succ=ansc;  // so far this is the deepest node for which current node is in the left
                ansc=ansc->left;
            }
            else ansc=ansc->right;
        }
        return succ;
    }
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
    BstNode* pr=getSuccessor(&root,8);
    if (pr!=NULL) print(pr->data);
    freeTree(&root);
}