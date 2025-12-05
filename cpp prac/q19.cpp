#include <iostream>
using namespace std;

// Base class
class A {
public:
    void displayA() {
        cout << "Class A" << endl;
    }
};

// Simple Inheritance
class B : public A {
public:
    void displayB() {
        cout << "Class B (Derived from A)" << endl;
    }
};

// Multiple Inheritance
class C {
public:
    void displayC() {
        cout << "Class C" << endl;
    }
};

class D : public A, public C {
public:
    void displayD() {
        cout << "Class D (Derived from A and C)" << endl;
    }
};

int main() {
    B b;
    b.displayA();
    b.displayB();

    D d;
    d.displayA();
    d.displayC();
    d.displayD();

    return 0;
}
