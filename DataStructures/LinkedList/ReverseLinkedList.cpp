#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Reverse(Node** head) {
    Node *curr=*head,*prev=NULL,*next;
    while (curr!=NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}

void Reverse1(Node** head) {
    Node* prev=*head;
    if (prev==NULL) return;
    Node* curr=prev->next;
    if (curr==NULL) return;
    Node* next=curr->next;
    prev->next=NULL;
    while (next!=NULL) {
        curr->next=prev;
        prev=curr;
        curr=next;
        next=next->next;
    }
    curr->next=prev;
    *head=curr;
    return;
}

void Print(Node *head) {
    cout<<"List is: ";
    while (head!=NULL) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
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
int main() {
    Node* head=NULL;
    Insert(2,&head);
    Insert(4,&head);
    Insert(6,&head);
    Insert(5,&head);
    Print(head);
    Reverse(&head);
    Print(head);
    freeList(&head);
    return 0;
}

