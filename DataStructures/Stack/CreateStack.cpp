#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* link;
};

void Push(int x,node** top) {
    node *temp=new node();
    temp->data=x;
    temp->link=*top;
    *top=temp;
    return;
}

int Pop(node** top) {
    if (*top==NULL) {
        cout<<"Stack can't be poped\n";
        return 0;
    }
    node* temp=*top;
    *top=temp->link;
    int c=temp->data;
    delete temp;
    return c;
}

void freeStack(node** top) {
    node* temp=*top;
    while (temp!=NULL) {
        node *pr=temp;
        temp=temp->link;
        delete pr;
    }
    return;
}

void Print(node* top) {
    while (top!=NULL) {
        cout<<top->data<<" ";
        top=top->link;
    }
    cout<<endl;
    return;
}

int main() {
    node* top=NULL;
    Push(2,&top);
    Print(top);
    Push(4,&top);
    Print(top);
    Push(6,&top);
    Print(top);
    int a=Pop(&top);
    cout<<a<<endl;
    Print(top);
    freeStack(&top);
    return 0;
}