#include <iostream>
using namespace std;

class Shape {
public:
    // Static Polymorphism: Function Overloading
    void area(int side) {
        cout << "Area of Square: " << side * side << endl;
    }

    void area(int length, int breadth) {
        cout << "Area of Rectangle: " << length * breadth << endl;
    }

    // Dynamic Polymorphism: Virtual Function
    virtual void display() {
        cout << "This is a generic shape." << endl;
    }
};

class Circle : public Shape {
public:
    void display() override {
        cout << "This is a circle." << endl;
    }
};


int main() {
    Shape s;
    Circle c;

    // Static Polymorphism
    s.area(7);           // Square
    s.area(2, 8);        // Rectangle

    // Dynamic Polymorphism
    Shape* ptr;
    ptr = &s;
    ptr->display();      // Calls Shape's display()

    ptr = &c;
    ptr->display();      // Calls Circle's display() due to virtual function

    return 0;
}


