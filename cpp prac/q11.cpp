#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Shape-circle" << endl;
    }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}

