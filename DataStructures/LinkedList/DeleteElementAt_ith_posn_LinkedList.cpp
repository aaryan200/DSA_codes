#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Delete(int posn,Node** head) {
    Node* temp1=*head;
    if (posn==1) {
        *head=temp1->next;
        // free(temp1);
        delete temp1;
        return;
    }
    int i;
    for (i=0;i<posn-2;i++) {
        temp1=temp1->next;
    }
    Node* temp2=temp1->next;
    temp1->next=temp2->next;
    // free(temp2);
    delete temp2;
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
    return;
}
int main() {
    Node* head=NULL;
    Insert(2,&head);
    Insert(4,&head);
    Insert(6,&head);
    Insert(5,&head);
    Print(head);
    int n;
    cin>>n;
    Delete(n,&head);
    Print(head);
    freeList(&head);
    return 0;
}