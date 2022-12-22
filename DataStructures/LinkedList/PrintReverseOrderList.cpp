#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void freeList(Node **head) {
    Node* temp=*head;
    while (temp!=NULL) {
        Node *pr=temp;
        temp=temp->next;
        delete pr;
    }
    return;
}
/*Insert at the end*/
void Insert(int data,Node** head) {
    Node *temp1=new Node();
    temp1->data=data;
    temp1->next=NULL;
    Node* temp2=*head;
    if (temp2==NULL) {
        *head=temp1;
        return;
    }
    while (temp2->next!=NULL) {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
/*Print using recursion*/
void Print(Node* head) {
    if (head==NULL) {
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    Print(head->next);
    return;
}
void RevPrint(Node* head) {
    if (head==NULL) {
        // cout<<endl;
        return;
    }
    RevPrint(head->next);
    cout<<head->data<<" ";
    // return;
}
int main() {
    Node* head=NULL;
    Insert(2,&head);
    Insert(4,&head);
    Insert(6,&head);
    Insert(5,&head);
    Print(head);
    // cout<<endl;
    // Reverse(&head);
    RevPrint(head);
    cout<<endl;
    freeList(&head);
    return 0;
}