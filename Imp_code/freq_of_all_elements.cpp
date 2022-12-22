#include <bits/stdc++.h>
using namespace std;
//The map::find() is a built-in function in C++ STL that returns an iterator or a constant iterator that refers
// to the position where the key is present in the map
map<int,int> Frequency(vector<int>& vec)
{
	// Define an map
	map<int, int> M;
	int n=vec.size();
	// Traverse vector vec check if
	// current element is present
	// or not
	for (int i = 0;i<n; i++) {

		// If the current element
		// is not found then insert
		// current element with
		// frequency 1
		if (M.find(vec[i]) == M.end()) {
			M[vec[i]] = 1;
		}

		// Else update the frequency
		else {
			M[vec[i]]++;
		}
	}

	// Traverse the map to print the
	// frequency
	// for (auto& it : M) {
	// 	cout << it.first << ' '
	// 		<< it.second << '\n';
	// }
    return M;
}

// Driver Code
int main()
{
	vector<int> vec = { 1, 2, 2, 3, 1, 4, 4, 5 };

	// Function call
	map<int,int> m=Frequency(vec);
    for (auto& it:m) cout<<it.first<<" "<<it.second<<"\n";
	return 0;
}
