#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Enqueue(Node** front,Node** rear, int x) {
    Node* temp1=new Node();
    temp1->data=x;
    temp1->next=NULL;
    if (*front==NULL and *rear==NULL) {
        *front=*rear=temp1;
        return;
    }
    (*rear)->next=temp1;
    *rear=temp1;
    return;
}

void Deque(Node** front,Node** rear) {
    if (*front==NULL) {
        cout<<"Can't be dequed\n";
        return;
    }
    if (*front==*rear) {
        delete(*front);
        *front=*rear=NULL;
        return;
    }
    Node *temp=(*front)->next;
    delete *front;
    *front=temp;
    return;
}

void Print(Node* front, Node* rear) {
    while (front!=rear) {
        cout<<front->data<<" ";
        front=front->next;
    }
    cout<<front->data<<endl;
    return;
}

void freeQueue(Node** front, Node**rear) {
    Node* temp=*front;
    while (temp!=*rear) {
        Node* pr=temp;
        temp=temp->next;
        delete pr;
    }
    delete temp;
    return;
}

int main() {
    Node *fr=NULL,*re=NULL;
    Enqueue(&fr,&re,2);
    Enqueue(&fr,&re,3);
    Enqueue(&fr,&re,4);
    Print(fr,re);
    Deque(&fr,&re);
    Print(fr,re);
    freeQueue(&fr,&re);
    return 0;
}