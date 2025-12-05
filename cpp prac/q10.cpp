#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    Student(string n, int r) {
        name = n;
        rollNumber = r;
        cout << "Parameterized constructor called." << endl;
    }

    // Function to display student details
    void displayInfo() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

int main() {
    // Using default constructor
    Student student1;
    student1.displayInfo();

    // Using parameterized constructor
    Student student2("Rangu", 24);
    student2.displayInfo();

    return 0;
}
