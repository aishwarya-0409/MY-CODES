#include <iostream>  // Use modern header
using namespace std; // Allows us to use cout and cin without std::

int main() { // Change void main() to int main()
    int a, b, c;

    cout << "Enter the value of a and b: ";  
    cin >> a >> b; // Fix spacing

    c = a + b;

    cout << "Sum is: " << c << endl; // Fix sum output format

    cin.get(); // Equivalent to getch() for pausing
    return 0; // Indicate successful execution
}





