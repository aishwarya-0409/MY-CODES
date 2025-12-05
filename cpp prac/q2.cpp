#include <iostream>
using namespace std;

class Subtractor {
public:
    double subtract(double a, double b); // Function declaration inside the class
};

// Function definition outside the class
double Subtractor::subtract(double a, double b) {
    return a - b;
}

int main() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    Subtractor s;
    double result = s.subtract(num1, num2);

    cout << "The difference is: " << result << endl;

    return 0;
}