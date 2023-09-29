#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define n 16
#define m 16
#define dest_size 4
#define SIZE 300

int q[SIZE][3];
int head = 0, tail = 0;
int neighborX[4] = {1, 0, -1, 0};
int neighborY[4] = {0, 1, 0, -1};

int min(int x, int y) {
    if (x < y) return x;
    return y;
}

void enqueue(int x, int y, int level) {
    if (tail - head == SIZE) {
        printf("Queue is full\n");
        return;
    }
    int i = tail % SIZE;
    q[i][0] = x;
    q[i][1] = y;
    q[i][2] = level;
    tail++;
    return;
}

void dequeue() {
    if (tail == head) {
        printf("Queue is empty\n");
        return;
    }
    int i = head % SIZE;
    q[i][0] = -1;
    q[i][1] = -1;
    q[i][2] = -1;
    head++;
    return;
}

int frontX() {
    int i = head % SIZE;
    return q[i][0];
}

int frontY() {
    int i = head % SIZE;
    return q[i][1];
}

int frontLevel() {
    int i = head % SIZE;
    return q[i][2];
}

bool isEmpty() {
    if (tail == head) return true;
    return false;
}


void bfs(int arr[n][m], int i, int j) {
    arr[i][j] = 0;
    tail = 0, head = 0;
    enqueue(i, j, 0);
    while (!isEmpty()) {
        int x = frontX(), y = frontY(), lev = frontLevel();
        arr[x][y] = min(arr[x][y], lev);
        dequeue();
        for (int k=0;k<4;k++) {
            int r = i + neighborX[k], c = j + neighborY[k];
            if (r >= 0 && r < n && c >= 0 && c < m) {
                if (arr[r][c] > lev + 1) {
                    // printf("%d %d %d\n", r, c, lev+1);
                    enqueue(r, c, lev+1);
                }
            }
        }
    }
}

void printArr(int arr[n][m]) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return;
}

int main() {
    // int n = 16;
    // int m = 4; // number of destinations
    int arr[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) arr[i][j] = 1000;
    }
    // printArr(arr);
    int dest[dest_size][2] = {{7, 7}, {7, 8}, {8, 7}, {8, 8}};
    for (int i=0;i<dest_size;i++) {
        bfs(arr, dest[i][0], dest[i][1]);
    }
    printArr(arr);
    return 0;
}