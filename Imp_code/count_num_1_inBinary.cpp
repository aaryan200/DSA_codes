#include<bits/stdc++.h>
using namespace std;
#define println(x) cout<<x<<endl;

long n_1(long n) {
    long ct=0;
    while (n>0) {
        n=n&(n-1);
        ct++;
    }
    return ct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n;
    cin>>n;
    cout<<n_1(n)<<endl;
    return 0;
}