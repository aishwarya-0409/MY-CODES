#include <iostream>
using namespace std;

class Multiplier {
public:
    double multiply(double a, double b) {
        return a * b;
    }
};

int main() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    Multiplier m;
    double result = m.multiply(num1, num2);

    cout << "The product is: " << result << endl;

    return 0;
}