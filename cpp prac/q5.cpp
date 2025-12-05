#include <iostream>
using namespace std;

// Inline function to calculate area
inline int area(int length, int breadth) {
    return length * breadth;
}

int main() {
    int l, b;

    cout << "Enter length of the rectangle: ";
    cin >> l;

    cout << "Enter breadth of the rectangle: ";
    cin >> b;

    cout << "Area of the rectangle is: " << area(l, b) << endl;

    return 0;
}
