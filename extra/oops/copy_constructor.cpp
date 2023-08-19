#include<bits/stdc++.h>
using namespace std;

class Hero {
public:
	char *name;
	int health;
	char level;
	Hero() {
		this->name = new char [100];
	}
	Hero(int health, int level, char name[]) {
		this->health = health;
		this->level = level;
		strcpy(this->name, name);
	}
	// Custom copy constructor, deep copy
	Hero(Hero& temp) {
		char* ch = new char[strlen(temp.name) + 1];
		strcpy(ch, temp.name);
		this->name = ch;
		this->health = temp.health;
		this->level = temp.level;
	}
	void print() {
		cout << "[ Health: "<< this->health << " Level: " << this->level << " Name: " << this->name <<  "]\n";
	}
};

int main() {
	char name[7] = "Ab";
	Hero a1(10, 'B', name);
	a1.print();
	Hero a2(a1);
	a2.print();
	a2.health = 15;
	a2.name[0] = 'B';
	a2.print();
	a1.print();
	return 0;
}
