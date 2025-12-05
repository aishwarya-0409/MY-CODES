
#include <iostream>
using namespace std;

// Function Template
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// Class Template
template <class T>
class Calculator {
public:
    T add(T a, T b) {
        return a + b;
    }
};

int main() {
    cout << "Max of 4 and 9: " << getMax(4, 9) << endl;
    cout << "Max of 2.5 and 1.5: " << getMax(2.5, 1.5) << endl;

    Calculator<int> intCalc;
    Calculator<float> floatCalc;

    cout << "Addition (int): " << intCalc.add(3, 7) << endl;
    cout << "Addition (float): " << floatCalc.add(2.5, 3.5) << endl;

    return 0;
}

Class A
Class B (Derived from A)
Class A
Class C
Class D (Derived from A and C)
