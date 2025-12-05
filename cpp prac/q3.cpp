#include <iostream>
using namespace std;

class Employee {
private:
    int empID;
    string name;
    string department;
    float salary;

public:
    // Function to enter employee details
    void getDetails() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cin.ignore(); // To clear the newline character from input buffer

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void displayDetails() {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID   : " << empID << endl;
        cout << "Name          : " << name << endl;
        cout << "Department    : " << department << endl;
        cout << "Salary        : $" << salary << endl;
    }
};

int main() {
    Employee emp;

    // Get and display employee details
    emp.getDetails();
    emp.displayDetails();

    return 0;
}
