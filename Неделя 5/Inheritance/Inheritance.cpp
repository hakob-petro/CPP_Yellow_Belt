#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal(const string& t) : Name(t) {}

    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& s) : Animal(s){};

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};