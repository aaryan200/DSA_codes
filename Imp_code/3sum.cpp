#include<bits/stdc++.h>
using namespace std;
#define println(x) cout<<x<<endl;

void solve() {
    int n;
    cin>>n;
    vector <long> v(n,0);
    vector <long> a(10,0);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        long temp=v[i]-((int)(v[i]/10))*10;
        a[temp]++;
    }
    for (int i=0;i<10;i++) {
        if (a[i]>0) {
            a[i]--;
            for (int j=0;j<10;j++) {
                if (a[j]>0) {
                    a[j]--;
                    for (int k=0;k<10;k++) {
                        if (a[k]>0) {
                            a[k]--;
                            if ((i+j+k)-((int)(i+j+k)/10)*10==3) {
                                cout<<"YES"<<endl;
                                return;
                            }
                            a[k]++;
                        }
                    }
                    a[j]++;
                }
            }
            a[i]++;
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,it;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}