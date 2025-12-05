#include <iostream>
#include <string>

using namespace std;

// Base class 1
class Person {
public:
    string name;

    Person(string n) : name(n) {
        cout << "Person constructor called for: " << name << endl;
    }

    void introduce() {
        cout << "Hi, my name is " << name << "." << endl;
    }

    ~Person() {
        cout << "Person destructor called for: " << name << endl;
    }
};

// Base class 2
class Employee {
public:
    int employeeId;

    Employee(int id) : employeeId(id) {
        cout << "Employee constructor called for ID: " << employeeId << endl;
    }

    void work() {
        cout << "Employee ID " << employeeId << " is working." << endl;
    }

    ~Employee() {
        cout << "Employee destructor called for ID: " << employeeId << endl;
    }
};

// Intermediate derived class (Multiple Inheritance)
class Manager : public Person, public Employee {
public:
    string department;

    Manager(string n, int id, string dept) : Person(n), Employee(id), department(dept) {
        cout << "Manager constructor called for: " << name << " (ID: " << employeeId << ", Dept: " << department << ")" << endl;
    }

    void manage() {
        cout << name << " is managing the " << department << " department." << endl;
    }

    ~Manager() {
        cout << "Manager destructor called for: " << name << endl;
    }
};

// Another intermediate derived class (Multiple Inheritance)
class Student {
public:
    string major;

    Student(string m) : major(m) {
        cout << "Student constructor called for major: " << major << endl;
    }

    void study() {
        cout << "Studying " << major << "." << endl;
    }

    ~Student() {
        cout << "Student destructor called for major: " << major << endl;
    }
};

// Final derived class (Hierarchical from Manager, and potentially others if needed)
// This example shows Manager as a base for a specific type of employee,
// and also demonstrates the "diamond problem" if Person was also a base of Student,
// which is avoided here for simplicity but highlights the hybrid nature.
class ProjectLead : public Manager { // Hierarchical inheritance from Manager
public:
    int projectsLed;

    ProjectLead(string n, int id, string dept, int pl) : Manager(n, id, dept), projectsLed(pl) {
        cout << "ProjectLead constructor called for: " << name << " (Projects Led: " << projectsLed << ")" << endl;
    }

    void leadProject() {
        cout << name << " is leading " << projectsLed << " projects." << endl;
    }

    ~ProjectLead() {
        cout << "ProjectLead destructor called for: " << name << endl;
    }
};

int main() {
    cout << "--- Hybrid Inheritance Demo ---" << endl;
    cout << "Atkuri Yashvani" << endl;
    cout << "reg.no: 24MEI10027" << endl;

    // Example of a Manager (Multiple Inheritance)
    Manager hrManager("Alice", 101, "HR");
    hrManager.introduce();
    hrManager.work();
    hrManager.manage();
    cout << endl;

    // Example of a ProjectLead (combining Multiple and Hierarchical)
    ProjectLead techLead("Bob", 202, "Development", 5);
    techLead.introduce(); // From Person via Manager
    techLead.work();      // From Employee via Manager
    techLead.manage();    // From Manager
    techLead.leadProject(); // From ProjectLead

    cout << "--- End of Hybrid Inheritance Demo ---" << endl;
    return 0;
}
