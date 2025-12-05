#include <iostream>
#include <string>

using namespace std;

// Grandparent class
class Vehicle {
public:
    string type;

    Vehicle(string t) : type(t) {
        cout << "Vehicle constructor called for: " << type << endl;
    }

    void start() {
        cout << type << " is starting." << endl;
    }

    ~Vehicle() {
        cout << "Vehicle destructor called for: " << type << endl;
    }
};

// Parent class (inherits from Vehicle)
class Car : public Vehicle {
public:
    string brand;

    Car(string t, string b) : Vehicle(t), brand(b) {
        cout << "Car constructor called for: " << brand << " " << type << endl;
    }

    void drive() {
        cout << brand << " is driving." << endl;
    }

    ~Car() {
        cout << "Car destructor called for: " << brand << " " << type << endl;
    }
};

// Child class (inherits from Car)
class SportsCar : public Car {
public:
    int topSpeed;

    SportsCar(string t, string b, int ts) : Car(t, b), topSpeed(ts) {
        cout << "SportsCar constructor called for: " << brand << " " << type << " (Top Speed: " << topSpeed << " mph)" << endl;
    }

    void accelerate() {
        cout << brand << " is accelerating to " << topSpeed << " mph." << endl;
    }

    ~SportsCar() {
        cout << "SportsCar destructor called for: " << brand << " " << type << endl;
    }
};

int main() {
    cout << "--- Multi-Level Inheritance Demo ---" << endl;
    cout << "Atkuri Yashvani" << endl;
    cout << "reg.no: 24MEI10027" << endl;

    // Create an object of the lowest derived class
    SportsCar mySportsCar("Car", "Ferrari", 200);

    // Access inherited member functions from all levels
    mySportsCar.start();
    mySportsCar.drive();
    mySportsCar.accelerate();

    cout << "--- End of Multi-Level Inheritance Demo ---" << endl;
    return 0;
}
