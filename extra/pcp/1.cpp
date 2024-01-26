#include <iostream>
#include <atomic>
using namespace std;

class InfoNext;  // Forward declaration of InfoNext

class Node {
public:
    int val;
    atomic<InfoNext*> infoNxt;

    Node();  // Declaration of the constructor
};

class InfoNext {
public:
    Node* nxt;
    bool marked;

    InfoNext() {
        nxt = nullptr;
        marked = false;
    }
};

// Definition of the Node constructor
Node::Node() {
    val = 0;
    infoNxt = new InfoNext();
}

int main() {
    Node* head = new Node();
    cout << "Works \n";
    return 0;
}
