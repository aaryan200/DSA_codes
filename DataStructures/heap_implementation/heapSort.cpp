#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "

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

void heapSort(vector<int>& arr, int n) {
    // build heap
    for (int i=n/2;i>0;i--) {
        heapify(arr, n, i);
    }
    int size = n;
    while (size > 1) {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 5;
    vector<int> arr = {-1, 10, -11, 4343, 11, 449};
    heapSort(arr, n);
    for (int i=1;i<=n;i++) prints(arr[i]);
    print("");
    // Time complexity O(nlogn)
    // Space complexity O(n)
    return 0;
}