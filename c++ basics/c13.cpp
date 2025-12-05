#include <bits/stdc++.h>
using namespace std;


vector<int>rm;

int decToBase(int n,int base){
    if(n==0) return 0;

   int rem = n%base;
   rm.push_back(rem);                         
   int base = number                           

   n=n/base;//this is quotient
   return decToBase(n,base);

}

int main(){

         int x, base;
    cout << "Enter a decimal number: ";
    cin >> x;
   cout << "Enter the base : ";
    cin >> base;

decToBase(x,base);
//cout << "Base " << base << " representation: ";
for (auto itr = rm.end()-1; itr >= rm.begin(); --itr)
        cout << *itr;

}