#include <iostream>
using namespace std;

// Class definition
class Student {
private:
    string name;
    int rollNumber;

public:
    // Constructor
    Student(string n, int r) { 
        name = n;
        rollNumber = r;
    }

    // Function to display student details
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

// Main function
int main() {
    // Creating object and passing values to constructor
    Student student1("Rangu",24);

    // Displaying student details
    student1.displayInfo();

    return 0; 
}
