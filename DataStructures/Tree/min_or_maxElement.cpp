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

int findMax(BstNode** root) {
    BstNode* temp=*root;
    if (temp==NULL) {
        cout<<"Tree is Empty"<<endl;
        return -1;
    }
    while (temp->right!=NULL) {
        temp=temp->right;
    }    
    return temp->data;
}

int findMinRec(BstNode** root) {
    BstNode* temp=*root;
    if (temp==NULL) {
        cout<<"Tree is Empty"<<endl;
        return -1;
    }
    if (temp->left==NULL) return temp->data;
    return findMinRec(&(temp->left));
}

int findMaxRec(BstNode** root) {
    BstNode* temp=*root;
    if (temp==NULL) {
        cout<<"Tree is Empty"<<endl;
        return -1;
    }
    if (temp->right==NULL) return temp->data;
    return findMinRec(&(temp->right));
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
    print(findMax(&root));
    print(findMin(&root));
    print(findMaxRec(&root));
    print(findMinRec(&root));
    return 0;
}