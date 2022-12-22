#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl

struct node
{
    int data;
    int height;
    node *left;
    node *right;
};

node* getNewNode(int x) {
    node* n1=new node();
    n1->data=x;
    n1->height=0;
    n1->left=NULL;
    n1->right=NULL;
    return n1;
}


/*Returns height of a node*/
int Height(node* t) {
    if (t==NULL) return -1;
    return(t->height);
}

/*Height(left)-Height(right)*/
int difference(node* t) {
    return Height(t->left)-Height(t->right);
}

/*Rotation towards right, clockwise*/
void rightRotate(node** t) {
    node *temp=(*t)->left;
    (*t)->left=temp->right;
    temp->right=*t;
    (*t)=temp;
    return;
}

/*Rotation towards left, anti-clockwise*/
void leftRotate(node **t) {
    node* temp=(*t)->right;
    (*t)->right=temp->left;
    temp->left=*t;
    (*t)=temp;
    return;
}

/*t->left is heavier than t->right and (t->left)->left is heavier than (t->left)->right*/
void leftLeft(node** t) {
    rightRotate(t);
    return;
}

/*t->right is heavier than t->left and (t->right)->right is heavier than (t->right)->left*/
void rightRight(node** t) {
    leftRotate(t);
    return;
}

/*t->left is heavier than t->right and (t->left)->right is heavier than (t->left)->left*/
void leftRight(node** t) {
    leftRotate(&((*t)->left));
    rightRotate(t);
    return;
}

/*t->right is heavier than t->left and (t->right)->left is heavier than (t->right)->right*/
void rightLeft(node** t) {
    rightRotate(&((*t)->right));
    leftRotate(t);
    return;
}

void Balance(node** t) {
    int diff=difference(*t);
    if (diff==1 or diff==0 or diff==-1) return;
    else if (diff>1) {
        int leftDiff=difference((*t)->left);
        if (leftDiff>0) leftLeft(t);
        else leftRight(t);
    }
    else if (diff<-1) {
        int rightDiff=difference((*t)->right);
        if (rightDiff<0) rightRight(t);
        else rightLeft(t);
    }
    return;
}

void Insert(node** root,int x) {
    if (*root==NULL) {
        *root=getNewNode(x);
        (*root)->height=0;
    }
    else if (x<= (*root)->data) {
        Insert(&((*root)->left),x);
        (*root)->height=max(Height((*root)->left),Height((*root)->right))+1;
        Balance(root);
        (*root)->height=max(Height((*root)->left),Height((*root)->right))+1;
    }
    else {
        Insert(&((*root)->right),x);
        (*root)->height=max(Height((*root)->left),Height((*root)->right))+1;
        Balance(root);
        (*root)->height=max(Height((*root)->left),Height((*root)->right))+1;
    }
    return;
}

/*Level order traversal*/
void levelOrder(node* root) {
    if (root==NULL) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* curr=q.front();
        cout<<curr->data<<" ";
        if (curr->left!=NULL) q.push(curr->left);
        if (curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
    cout<<endl;
    return;
}


void freeTree(node** root) {
    node* temp=*root;
    if (temp==NULL) return;
    freeTree(&(temp->left));
    freeTree(&(temp->right));
    delete temp;
    return;
}

int main() {
    node* root=NULL;
    Insert(&root,5);
    Insert(&root,7);
    Insert(&root,10);
    // Insert(&root,11);
    // Insert(&root,12);
    // Insert(&root,13);
    // Insert(&root,15);
    // Insert(&root,16);
    // Insert(&root,17);
    print(root->data);
    print(difference(root));
    levelOrder(root);
    // cout<<endl;
    // rightRight(&(root->right));
    // levelOrder(root);
    freeTree(&root);
    return 0;
}