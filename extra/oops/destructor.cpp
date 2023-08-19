#include<bits/stdc++.h>
using namespace std;

class Hero {
public:
    int health;
    char *name;
    Hero() {
        this->health = 0;
        this->name = new char[100];
    }
    ~Hero() {
        cout << "Destructor called " << endl;
        delete name;
    }
};

Hero f(int h) {
    Hero h1;
    h1.health = h;
    return h1;
}

int main()
{
    Hero h1 = f(10);
    // Hero* h2 = new Hero;

    return 0;
}