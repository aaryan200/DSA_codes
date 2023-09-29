#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000
#define n 16
#define m 16
#define dest_size 4

template <class T>
class Queue {
private:
    T arr[SIZE];
    int tail, head;
public:
    Queue() {
        this->tail = 0;
        this->head = 0;
        for (int i=0;i<SIZE;i++) this->arr[i] = T();
    }
    void enqueue(T x) {
        if (this->tail - this->head == SIZE) {
            cout << "Queue is full" << endl;
            return;
        }
        this->arr[(this->tail)%SIZE] = x;
        this->tail++;
        return;
    }
    T dequeue() {
        if (this->tail == this->head) {
            cout << "Queue is empty" << endl;
            return T();
        }
        T x = this->arr[(this->head)%SIZE];
        this->head++;
        return x;
    }
    bool isEmpty() {
        return this->tail == this->head;
    }
};

class triplet {
public:
    int x, y, z;
    triplet() {
        this->x = -1;
        this->y = -1;
        this->z = -1;
    }
    triplet(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int neighborX[4] = {1, 0, -1, 0};
int neighborY[4] = {0, 1, 0, -1};

void bfs(int arr[n][m], int i, int j) {
    arr[i][j] = 0;
    Queue<triplet> q;
    q.enqueue(triplet(i, j, 0));
    while (!q.isEmpty()) {
        triplet t = q.dequeue();
        for (int k=0;k<4;k++) {
            int x = t.x + neighborX[k];
            int y = t.y + neighborY[k];
            if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] > t.z + 1) {
                arr[x][y] = t.z + 1;
                q.enqueue(triplet(x, y, t.z + 1));
            }
        }
    }
}

void printArr(int arr[n][m]) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int orientation(int orient,char turning) {
    if (turning== 'L') {
        orient-=1;
        if (orient==-1)
            orient=3;
    }
    else if(turning== 'R') {
        orient+=1;
        if (orient==4)
            orient=0;
    }
    else if(turning== 'B') {
        if (orient==0)
            orient=2;
        else if (orient==1)
            orient=3;
        else if (orient==2)
            orient=0;
        else if (orient==3)
            orient=1;
    }

    return(orient);
}

void updateCoordinates(int& x,int &y,int orient) {

    if (orient==0)
        y+=1;
    else if (orient==1)
        x+=1;
    else if (orient==2)
        y-=1;
    else if (orient==3)
        x-=1;
    return;
}

void updateWalls(int x,int y,int orient,bool L,bool R,bool F, int flood[n][m]) {
    if(L and R and F) {
        if (orient==0)
            flood[y][x]= 13;
        else if (orient==1)
            flood[y][x]= 12;
        else if (orient==2)
            flood[y][x]= 11;
        else if (orient==3)
            flood[y][x]= 14;
    }

    else if (L and R and !F) {
        if (orient==0 or orient== 2)
            flood[y][x]= 9;
        else if (orient==1 or orient==3)
            flood[y][x]= 10;
    }

    else if (L and F and !R) {
        if (orient==0)
            flood[y][x]= 8;
        else if (orient==1)
            flood[y][x]= 7;
        else if (orient==2)
            flood[y][x]= 6;
        else if (orient==3)
            flood[y][x]= 5;
    }

    else if (R and F and !L) {
        if (orient==0)
            flood[y][x]= 7;
        else if (orient==1)
            flood[y][x]= 6;
        else if (orient==2)
            flood[y][x]= 5;
        else if (orient==3)
            flood[y][x]= 8;
    }

    else if(F) {
        if (orient==0)
            flood[y][x]= 2;
        else if (orient==1)
            flood[y][x]= 3;
        else if (orient==2)
            flood[y][x]= 4;
        else if (orient==3)
            flood[y][x]= 1;
    }

    else if(L) {
        if (orient==0)
            flood[y][x]= 1;
        else if (orient==1)
            flood[y][x]= 2;
        else if (orient==2)
            flood[y][x]= 3;
        else if (orient==3)
            flood[y][x]= 4;
    }

    else if(R) {
        if (orient==0)
            flood[y][x]= 3;
        else if (orient==1)
            flood[y][x]= 4;
        else if (orient==2)
            flood[y][x]= 1;
        else if (orient==3)
            flood[y][x]= 2;
    }

    else flood[y][x]= 15;
    return;
}

void floodFill(int flood[n][m]) {
    
}

int main() {
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