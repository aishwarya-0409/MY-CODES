#include <iostream>
using namespace std;

class PrimeChecker {
private:
    int number;

public:
    // Function to get input from user
    void getInput() {
        cout << "Enter a number: ";
        cin >> number;
    }

    // Function to check if the number is prime
    void checkPrime() {
        bool isPrime = true;

        if (number <= 1) {
            isPrime = false;
        } else {
            for (int i = 2; i * i <= number; i++) {
                if (number % i == 0) {
                    isPrime = false; 
                    break;
                }
            }
        }

        // Output result
        if (isPrime)
            cout << number << " is a Prime Number." << endl;
        else
            cout << number << " is NOT a Prime Number." << endl;
    }
};

int main() {
    PrimeChecker pc;

    pc.getInput();
    pc.checkPrime();

    return 0;
}
