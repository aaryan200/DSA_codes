#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

// string.erase(starting_pos,len_of_substring) will erase len_of_substring length including starting_pos

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s="Aaryan";
    print(s);
    s.erase(1,2); // Ayan
    print(s);
    return 0;
}