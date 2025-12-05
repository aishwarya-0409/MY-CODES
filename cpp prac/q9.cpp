#include <iostream>
using namespace std;

// Forward declaration
class B;

class A {
private:
    int numA;

public:
    A(int x) {
        numA = x;
    }

    // Friend function
    friend void showSum(A, B);

    // Friend class declaration
    friend class B;
};

class B {
private:
    int numB;

public:
    B(int y) {
        numB = y;
    }

    // Accessing private member of class A (since B is a friend)
    void showDifference(A objA) {
        cout << "Difference (B - A): " << numB - objA.numA << endl;
    }

    // Friend function declared inside class A can access private members
    friend void showSum(A, B);
};

// Friend function definition
void showSum(A objA, B objB) {
    cout << "Sum (A + B): " << objA.numA + objB.numB << endl;
}

int main() {
    A a(40);
    B b(20);

    // Friend function call
    showSum(a, b);

    // Friend class method call
    b.showDifference(a);

    return 0;
}
