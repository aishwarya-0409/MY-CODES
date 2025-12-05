#include <iostream>
#include <string>

using namespace std;

// Base class
class Animal {
public:
    string name;

    Animal(string n) : name(n) {
        cout << "Animal constructor called for: " << name << endl;
    }

    void eat() {
        cout << name << " is eating." << endl;
    }

    ~Animal() {
        cout << "Animal destructor called for: " << name << endl;
    }
};

// Derived class (inherits from Animal)
class Dog : public Animal {
public:
    string breed;

    Dog(string n, string b) : Animal(n), breed(b) {
        cout << "Dog constructor called for: " << name << " (" << breed << ")" << endl;
    }

    void bark() {
        cout << name << " the " << breed << " is barking." << endl;
    }

    ~Dog() {
        cout << "Dog destructor called for: " << name << " (" << breed << ")" << endl;
    }
};

int main() {
    cout << "--- Simple Inheritance Demo ---" << endl;
    cout << "Atkuri Yashvani" << endl;
    cout << "reg.no: 24MEI10027" << endl;

    // Create an object of the derived class
    Dog myDog("Buddy", "Golden Retriever");

    // Access inherited member function
    myDog.eat();

    // Access derived class member function
    myDog.bark();

    cout << "--- End of Simple Inheritance Demo ---" << endl;
    return 0;
}
