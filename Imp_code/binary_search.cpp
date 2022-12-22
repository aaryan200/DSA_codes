#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
/*v is sorted in ascending order*/
int indOfx(int x,vector<int> v) {
    int n=v.size(),l=0,h=n-1,ind=-1;
    while (h-l>1) {
        int mid=(l+h)/2;
        if (x>v[mid]) l=mid;
        else if (x<v[mid]) h=mid;
        else {
            ind=mid;
            break;
        }
    }
    if (x==v[l]) ind=l;
    else if (x==v[h]) ind=h;
    return ind;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,se;
    cin>>n;
    vector <int> v(n,0);
    for (int i=0;i<n;i++) cin>>v[i];
    cin>>se;
    print(indOfx(se,v));
    return 0;
}