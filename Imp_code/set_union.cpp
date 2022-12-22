#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,pair<int,int>> ppi;

// template <typename InIt1, typename InIt2, typename OutIt>
// OutIt unordered_set_intersection(InIt1 b1, InIt1 e1, InIt2 b2, InIt2 e2, OutIt out) {
//     while (!(b1 == e1)) {
//         if (!(std::find(b2, e2, *b1) == e2)) {
//             *out = *b1;
//             ++out;
//         }

//         ++b1;
//     }

//     return out;
// }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> s1={1,2,3};
	unordered_set<int> s2={4,5,6};
	// unordered_set<int>::iterator it,st;
	set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s1,s1.begin()));
	// for (st=s1.begin();st!=s1.end();st++) cout<<*st<<endl;
	for (auto& it:s1) cout<<it<<endl;
	return 0;
}