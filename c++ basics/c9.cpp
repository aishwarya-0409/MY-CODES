#include <iostream>
#include <vector>
#include <functional> // for std::function

// Function to generate numbers based on a provided algorithm function
std::vector<int> generateNumbers(int size, std::function<int(int)> algorithm) {
    std::vector<int> numbers;
    for (int i = 0; i < size; ++i) {
        numbers.push_back(algorithm(i));
    }
    return numbers;
}

// Fibonacci function with memoization
int fib(int n) {
    static std::vector<int> fb(50, 0); // Memoization array, assuming we need up to fib(49)

    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    if (fb[n] != 0) {
        return fb[n];
    }
    fb[n] = fib(n - 1) + fib(n - 2);
    return fb[n];
}

int main() {
    int size = 12; // Specify the size of the list

    // Generate the list of Fibonacci numbers using the fib function
    std::vector<int> result = generateNumbers(size, fib);

    // Print the generated Fibonacci numbers
    std::cout << "Generated Fibonacci Numbers: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
