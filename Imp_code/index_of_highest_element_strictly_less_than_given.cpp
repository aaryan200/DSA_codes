// C++ program to find first element that
// is strictly smaller than given target in a sorted array.
#include<bits/stdc++.h>
using namespace std;

int next(vector<int>& v, int target)
{
    int end=v.size();
    if(end == 0) return -1;
    if (target > v[end - 1]) return end-1;

    int start = 0;

    int ans = -1;
    while (start <= end)
    {
    int mid = (start + end) / 2;
    if (v[mid] >= target)
    {
    end = mid - 1;
    }
    else
    {
    ans = mid;
    start = mid + 1;
    }
    }
    return ans;
}
int main()
{
    vector <int> v = { 1, 2, 3, 5, 8, 12 };
    cout << (next(v, 15));
    return 0;
}