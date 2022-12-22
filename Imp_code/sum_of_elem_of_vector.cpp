#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <double> v{1.5,2.5,3.0};
    cout<<accumulate(v.begin(),v.end(),0.0)<<endl;
    // Use 0 if all are integers
    return 0;
}