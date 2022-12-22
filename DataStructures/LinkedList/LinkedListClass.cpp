#include<bits/stdc++.h>
using namespace std;
// #define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
template <typename dt>
class llist
{
private:
    class node {
    public:
        dt data;
        node* next;
    };
    node* hd;

    /*Insert at top of list*/
    void Insert(node** head,dt x) {
        node *temp=new node();
        temp->data=x;
        temp->next=NULL;
        if (*head!=NULL) temp->next=*head;
        *head=temp;
        return;
    }
    void Insert_At(dt data,int posn,node** head) {
        node *temp1=new node();
        temp1->data=data;
        temp1->next=NULL;
        if (posn==1) {
            temp1->next=*head;
            *head=temp1;
            return;
        }
        node *temp2=*head;
        for (int i=0;i<posn-2;i++) {
            temp2=temp2->next;
        }
        temp1->next=temp2->next;
        temp2->next=temp1;
        return;
    }
    void Print(node *head) {
        cout<<"List is: ";
        while (head!=NULL) {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    void Delete(int posn,node** head) {
        node* temp1=*head;
        if (posn==1) {
            *head=temp1->next;
            delete temp1;
            return;
        }
        for (int i=0;i<posn-2;i++) {
            temp1=temp1->next;
        }
        node* temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        return;
    }
    void freeList(node **head) {
        node* temp=*head;
        while (temp!=NULL) {
            node *pr=temp;
            temp=temp->next;
            delete pr;
        }
        return;
    }
public:
    llist() {
        hd=NULL;
    }
    void insert(dt x) {
        return Insert(&hd,x);
    }
    void insert_at(dt x,int posn) {
        return Insert_At(x,posn,&hd);
    }
    void deelete(int posn) {
        return Delete(posn,&hd);
    }
    void freee() {
        return(freeList(&hd));
    }
    void print() {
        return(Print(hd));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llist <int> li;
    li.insert(8);
    li.insert(19);
    li.insert(29);
    li.print();
    li.deelete(1);
    li.print();
    li.freee();
    return 0;
}