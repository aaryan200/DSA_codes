#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "geeksforgeeks a computer science";
    string c = "geeks";
    // Find first occurrence of 'geeks' in str
    int found = str.find(c);
    if (found != string::npos)
        cout << "First occurrence is " << found << endl;
    // Find next occurrence of 'geeks' str
    found = str.find(c, found+1); // found+1 is starting position from where we have to find "geeks"
    if (found != string::npos)
        cout << "Next occurrence is " << found << endl;
    return 0;
}