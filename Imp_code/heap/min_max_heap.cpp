#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;
void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
void showpq1(
    priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> gquiz; // max heap
    // if pair to be stored then priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
    priority_queue<ppi,vector<ppi>,greater<ppi>> minh1; // for some ques
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
    cout << "The priority queue gquiz is : ";
    showpq(gquiz); // 30 20 10 5 1
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz); // 20 10 5 1
    print("");

    priority_queue<int, vector<int>, greater<int> > gquiz1; // min heap
    gquiz1.push(10);
    gquiz1.push(30);
    gquiz1.push(20);
    gquiz1.push(5);
    gquiz1.push(1);
    cout << "The priority queue gquiz1 is : ";
    showpq1(gquiz1); // 1 5 10 20 30
    cout << "\ngquiz1.size() : " << gquiz1.size();
    cout << "\ngquiz.top() : " << gquiz1.top();
    cout << "\ngquiz.pop() : ";
    gquiz1.pop();
    showpq1(gquiz1); // 5 10 20 30
    return 0;
}