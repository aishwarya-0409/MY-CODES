#include <bits/stdc++.h>
using namespace std;



int main() {
 
    
    string str ="1011";
    int sum = 0;
   

    cout<<str[0]<<str[1]<<str[2]<<str[3]<<endl;

   printf("\n%d",str[1]);// printing ascii value of '0'
   
   for(int i=str.length()-1;i>=0;i--){
    sum = sum + (str[i]-48)*pow(2,str.length()-1-i);
    cout<<sum<<endl;
   }
    
   cout<<sum;
    
  
  return 0;
}