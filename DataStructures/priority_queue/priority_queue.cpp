// Priority queue;
#include <bits/stdc++.h>
using namespace std;
class MinPriorityQueue{
    private:
    vector<int> heap;
    int heapSize = 0;
    void swim(int k) {
        int parent = (k-1)/2,t;
        while(heap[parent] > heap[k]) {
            t = heap[parent];
            heap[parent] = heap[k];
            heap[k] = t;
            k = parent;
            parent = (k-1)/2;
        }
    }
    void sink(int k) {
        int left,right,smallest,t;
        while(true) {
            left = 2*k+1; right = 2*k+2; smallest = 2*k+1;
            if(right < heapSize && heap[right] < heap[left]) {
                smallest = right;
            }
            if(left >= heapSize || heap[k] < heap[smallest]) break;
            t = heap[k];
            heap[k] = heap[smallest];
            heap[smallest] = t;
            k = smallest;
        }
    }
    public:
    void add(int n) {
        heap.push_back(n);
        swim(heapSize);
        heapSize++;
    }
    void removeAt(int k) {
        if (heap.empty()) return;
        heapSize--;
        int rdata = heap[k],t;
        heap[k] = heap[heapSize];
        heap.pop_back();
        t = heap[k];
        sink(k);
        if(t = heap[k]) swim(k);
    }
    void remove(int n) {
        for(int i = 0; i < heapSize; i++) {
            if(heap[i] == n) {
                removeAt(i);
                return;
            }
        }
    }
    int poll() {
        int t = heap[0];
        removeAt(0);
        return t;
    }
    void print() {
        for(auto i = heap.begin(); i != heap.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    int capacity() {
        return heapSize;
    }
    bool empty() {
        if(heap.empty()) return true;
        return false;
    }
};
int main() {
    int n,k,i;
    MinPriorityQueue q;
    cin >> n;
    for(i=0; i<n; i++) {
        cin >> k;
        q.add(k);
    }
    q.print();
    while(!q.empty()) {
        cout << q.poll() << endl;
    }
    return 0;
}