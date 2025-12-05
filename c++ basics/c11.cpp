#include <bits/stdc++.h>
using namespace std;

int printFibonacci(int n) {
    if(n<=1){
        return n;
    }
   
    int a = 0, b = 1, c;
    cout << "Fibonacci Sequence up to " << n << " terms:" << std::endl;
    cout << a << " " << b << " ";

    for (int i = 2; i < n; ++i) {
        c = a + b;
       cout << c << " ";
        a = b;
        b = c;
    }
   cout << endl;
   return c ;
}

int main() {
    int terms = 10; // Number of terms in Fibonacci sequence to print
    printFibonacci(terms);
    return 0;
}
