#include <iostream>
using namespace std;

// Class definition
class Student {
private:
    string name;

public:
    // Constructor
    Student(string n) {
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }

    // Function to display student name
    void displayName() {
        cout << "Student Name: " << name << endl;
    }
};

// Main function
int main() {
    {
        Student s1("Rangu");
        s1.displayName();
    } // s1 goes out of scope here, so destructor is called

    cout << "End of main function." << endl;
    return 0;
}
