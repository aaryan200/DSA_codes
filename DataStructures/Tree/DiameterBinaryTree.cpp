#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int height(Node* nd) {
    if (nd == NULL) return 0;
    int leftH = height(nd->left);
    int rightH = height(nd->right);
    return 1 + max(leftH, rightH);
}

// Will return diameter and height of nd
pair<int,int> diameterUtil(Node* nd) {
    if (nd == NULL) {
        return {0, 0};
    }
    pair<int,int> op1 = diameterUtil(nd->left);
    pair<int,int> op2 = diameterUtil(nd->right);
    int op3 = 1 + op1.second + op2.second;
    int h = 1 + max(op1.second, op2.second);
    return {max({op1.first, op2.first, op3}), h};
}

int diameter(Node* nd) {
    pair<int,int> temp = diameterUtil(nd);
    return temp.first;
}

int main() {
    return 0;
}