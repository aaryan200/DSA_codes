#include <bits/stdc++.h>

using namespace std;

// For vector
int main()
{
    vector<int> vect{ 3, 2, 1, 3, 3, 5, 3 };
    cout << "Number of times 3 appears : "
         << count(vect.begin(), vect.end(), 3);
  
    return 0;
}
// For string
// using namespace std;
  
// int main()
// {
//     string str = "geeksforgeeks";
  
//     cout << "Number of times 'e' appears : " 
//          << count(str.begin(), str.end(), 'e');
  
//     return 0;
// }