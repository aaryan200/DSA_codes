#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Print(Node *head) {
    cout<<"List is: ";
    while (head!=NULL) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void Insert(int data,int posn,Node** head) {
    Node *temp1=new Node();
    temp1->data=data;
    temp1->next=NULL;
    if (posn==1) {
        temp1->next=*head;
        *head=temp1;
        return;
    }
    Node *temp2=*head;
    for (int i=0;i<posn-2;i++) {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
    // delete temp2;
    return;
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

int main() {
    Node* head=NULL;
    Insert(2,1,&head); // List: 2
    Print(head);
    Insert(3,2,&head); // List: 2,3
    Print(head);
    Insert(4,1,&head); // List: 4,2,3
    Print(head);
    Insert(5,2,&head); // List: 4,5,2,3
    Print(head);
    freeList(&head);
    return 0;
}