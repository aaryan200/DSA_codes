#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "

// 
// Using array implementation, index of children of i are 2*i and 2*i + 1, arr[0] = none
// Index of parent of i is i/2
class MaxHeap {
public:
    vector<ll> arr;
    int size;
    MaxHeap() {
        this->size = 0;
        this->arr.push_back(-1);
    }
    void insert(int val) {
        // O(log n)
        this->size = this->size + 1;
        // Push at the end
        arr.push_back(val);
        // Propogate the last node to its correct position
        int index = this->size, parent = (this->size) / 2;
        while (index > 1) {
            if (this->arr[parent] < this->arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
                parent = index/2;
            }
            else break;
        }
        return;
    }
    void pop() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        // Put the value of last node at node 1
        this->arr[1] = this->arr[this->size];
        // Delete the last node
        arr.pop_back();
        // Reduce size
        this->size = this->size - 1;
        // Propogate root node to its correct position
        int index = 1;
        while (index <= size) {
            // arr[index] should be more than its children
            int swapIndex = index;
            int leftChild = 2*index, rightChild = 2*index + 1;
            if (leftChild <= size and arr[swapIndex] < arr[leftChild]) {
                swapIndex = leftChild;
            }
            // If rightChild is more than leftChild then it will automatically be assigned as swapIndex in next if condition
            if (rightChild <= size and arr[swapIndex] < arr[rightChild]) {
                swapIndex = rightChild;
            }
            if (index != swapIndex) {
                swap(arr[index], arr[swapIndex]);
                index = swapIndex;
            }
            else break;
        }
        return;
    }
    void printHeap() {
        for (int i=1;i<=size;i++) cout << arr[i]<<" ";
        cout << '\n';
    }
};

// Convert array to heap such that i is at its correct position
void heapify(vector<int>& arr, int n, int i) {
    // Check if both of its children have a less value or not
    // If yes then its already heapified
    // Otherwise swap it with that child and heapify that child
    int larger = i;
    int leftIndex = 2*i, rightIndex = 2*i +1;
    if (leftIndex <= n && arr[leftIndex] > arr[larger]) {
        larger = leftIndex;
    }
    if (rightIndex <= n and arr[rightIndex] > arr[larger]) {
        larger = rightIndex;
    }
    if (larger != i) {
        swap(arr[larger], arr[i]);
        // Swap it with that child and check that child
        heapify(arr, n, larger);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    MaxHeap h;
    h.insert(100);
    h.insert(52);
    h.insert(53);
    h.insert(48);
    h.insert(50);
    h.printHeap();
    h.pop();
    h.printHeap();

    print("Heapify");
    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // nodes from (n/2 + 1) to n are leaf nodes
    // Building a heap is O(n)
    for (int i=n/2; i>0;i--) heapify(arr, n, i);
    for (int i=1;i<=n;i++) prints(arr[i]);
    print("");
    return 0;
}