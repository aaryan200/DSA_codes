#include <iostream>     // std::cout
#include <valarray>     // std::valarray, std::slice
using namespace std;

int main ()
{
    int init[]= {10,20,30,40};
    valarray<int> first;                             // (empty)
    valarray<int> second (5);                        // 0 0 0 0 0
    valarray<int> third (10,3);                      // 10 10 10
    valarray<int> fourth (init,4);                   // 10 20 30 40
    valarray<int> fifth (fourth);                    // 10 20 30 40
    valarray<int> sixth (fifth[slice(1,2,1)]);  // 20 30
    for (int i=0;i<5;i++) cout<<second[i]<<" ";
    cout<<endl;
    cout << "sixth sums " << sixth.sum() << '\n';

    return 0;
}