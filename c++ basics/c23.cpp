//If we list all the natural numbers below  10 that are multiples of 3 or 5, we get 3,5,6 and 9 .
// The sum of these multiples is 23.

//Find the sum of all the multiples of 3 or 5 below N.

//Input Format :
//First line contains  that denotes the number of test cases. 
//This is followed by  lines, each containing an integer, .

//Output Format :
//For each test case, print an integer that denotes the sum of all the multiples of  or  below .

//Sample Input 0

//2
//10
//100
//Sample Output 0

//23
//2318
//Explanation 0




#include <bits/stdc++.h>
using namespace std;



int main() {
     int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        int sum = 0;
    
  for (int i = n-1; i >= 1; i--) {
    if (i % 3 == 0 || i % 5 == 0){
      sum = sum+ i;
   
    }
  }
   cout << sum << "\n";
    }
       
  
  return 0;
}