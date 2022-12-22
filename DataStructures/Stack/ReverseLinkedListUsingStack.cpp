#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Reverse(Node** head) {
    if (*head==NULL) return;
    stack <Node*> s;
    Node* temp=*head;
    while (temp!=NULL) {
        s.push(temp);
        temp=temp->next;
    }
    Node* temp1=s.top();
    *head=temp1;
    s.pop();
    while (!s.empty()) {
        temp1->next=s.top();
        s.pop();
        temp1=temp1->next;
    }
    temp1->next=NULL;
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
    // int n;
    // cin>>n;
    // Delete(n,&head);
    Reverse(&head);
    Print(head);
    freeList(&head);
    return 0;
}