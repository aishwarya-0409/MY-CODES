#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    Calculator operator + (const Calculator &obj) {
        Calculator res;
        res.value = value + obj.value;
        return res;
    }

    void setValue(int v) {
        value = v;
    }

    void show() {
        cout << "Value: " << value << endl;
    }

private:
    int value;
};

int main() {
    Calculator c1, c2, c3;
    c1.setValue(10);
    c2.setValue(20);
    c3 = c1 + c2;
    c3.show();

    cout << "Overloaded add(int): " << c1.add(5, 3) << endl;
    cout << "Overloaded add(double): " << c1.add(2.5, 4.5) << endl;

    return 0;
}
