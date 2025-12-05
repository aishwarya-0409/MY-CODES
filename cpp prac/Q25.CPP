#include <iostream>
#include <string>

using namespace std;

// Base class
class Shape {
public:
    string color;

    Shape(string c) : color(c) {
        cout << "Shape constructor called for color: " << color << endl;
    }

    void displayColor() {
        cout << "This shape is " << color << "." << endl;
    }

    ~Shape() {
        cout << "Shape destructor called for color: " << color << endl;
    }
};

// Derived class 1 (inherits from Shape)
class Circle : public Shape {
public:
    double radius;

    Circle(string c, double r) : Shape(c), radius(r) {
        cout << "Circle constructor called with radius: " << radius << endl;
    }

    void calculateArea() {
        cout << "Area of " << color << " circle: " << 3.14159 * radius * radius << endl;
    }

    ~Circle() {
        cout << "Circle destructor called with radius: " << radius << endl;
    }
};

// Derived class 2 (inherits from Shape)
class Rectangle : public Shape {
public:
    double length;
    double width;

    Rectangle(string c, double l, double w) : Shape(c), length(l), width(w) {
        cout << "Rectangle constructor called with dimensions: " << length << "x" << width << endl;
    }

    void calculateArea() {
        cout << "Area of " << color << " rectangle: " << length * width << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor called with dimensions: " << length << "x" << width << endl;
    }
};

// Derived class 3 (inherits from Shape)
class Triangle : public Shape {
public:
    double base;
    double height;

    Triangle(string c, double b, double h) : Shape(c), base(b), height(h) {
        cout << "Triangle constructor called with base: " << base << ", height: " << height << endl;
    }

    void calculateArea() {
        cout << "Area of " << color << " triangle: " << 0.5 * base * height << endl;
    }

    ~Triangle() {
        cout << "Triangle destructor called with base: " << base << ", height: " << height << endl;
    }
};

int main() {
    cout << "--- Hierarchical Inheritance Demo ---" << endl;
    cout << "Atkuri Yashvani" << endl;
    cout << "reg.no: 24MEI10027" << endl;

    // Create objects of different derived classes
    Circle redCircle("Red", 5.0);
    redCircle.displayColor();
    redCircle.calculateArea();
    cout << endl;

    Rectangle blueRectangle("Blue", 4.0, 6.0);
    blueRectangle.displayColor();
    blueRectangle.calculateArea();
    cout << endl;

    Triangle greenTriangle("Green", 3.0, 8.0);
    greenTriangle.displayColor();
    greenTriangle.calculateArea();

    cout << "--- End of Hierarchical Inheritance Demo ---" << endl;
    return 0;
}
