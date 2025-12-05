#include <iostream>
#include <string>

using namespace std;

// Base class 1
class Swimmer {
public:
    void swim() {
        cout << "Can swim." << endl;
    }
};

// Base class 2
class Walker {
public:
    void walk() {
        cout << "Can walk." << endl;
    }
};

// Derived class (inherits from both Swimmer and Walker)
class Amphibian : public Swimmer, public Walker {
public:
    string name;

    Amphibian(string n) : name(n) {
        cout << "Amphibian constructor called for: " << name << endl;
    }

    void displayAbilities() {
        cout << name << " has the following abilities:" << endl;
        swim(); // Inherited from Swimmer
        walk(); // Inherited from Walker
    }

    ~Amphibian() {
        cout << "Amphibian destructor called for: " << name << endl;
    }
};

int main() {
    cout << "--- Multiple Inheritance Demo ---" << endl;
    cout << "Atkuri Yashvani" << endl;
    cout << "reg.no: 24MEI10027" << endl;

    // Create an object of the derived class
    Amphibian frog("Froggy");

    // Access member functions from both base classes through the derived class object
    frog.displayAbilities();

    cout << "--- End of Multiple Inheritance Demo ---" << endl;
    return 0;
}

