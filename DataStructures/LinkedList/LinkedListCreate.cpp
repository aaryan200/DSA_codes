#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

/*Insert at top of list*/
void Insert(Node** ptrhead,int x) {
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if (*ptrhead!=NULL) temp->next=*ptrhead;
    *ptrhead=temp;
    // delete temp;
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
int main() {
    int n,i,x;
    Node* head=NULL; //Head node, initially linked list is empty
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>x;
        Insert(&head,x);
        Print(head);
    }
    freeList(&head);
    return 0;
}