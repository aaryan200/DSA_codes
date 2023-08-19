#include<bits/stdc++.h>
using namespace std;

class Human {
public:
    int health;
    int age;
    int weight;

    int getAge() {
        return this->age;
    }
    void setWeight(int w) {
        this->weight  = w;
    }
};

// Inherited from Human using public access modifier
class Male: public Human {
public:
    string color;
    void sleep() {
        cout << "Male sleeping \n";
    }
};

int main()
{
    Male m1;
    m1.sleep();
    return 0;
}