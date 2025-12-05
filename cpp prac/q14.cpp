#include <iostream>
using namespace std;

template <class T>
T largest(T a, T b, T c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}

int main() {
    cout << "Largest of 3, 7, 5 is: " << largest(3, 7, 5) << endl;
    cout << "Largest of 4.2, 1.9, 6.3 is: " << largest(4.2, 1.9, 6.3) << endl;
    cout << "Largest of 'a', 'z', 'm' is: " << largest('a', 'z', 'm') << endl;

    return 0;
}
