#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
 cout << "Enter a positive integer: ";
    cin >> n;
       int sum = 0;
    
  for (int i = 1; i <= n; ++i) 
  sum = sum+ i;
    cout << sum << "\n";
  
  return 0;
}