#include <bits/stdc++.h>
using namespace std;


int main() {

    string str1 ="145";
    string str2 ="22";

    int n1 = 0 ;
    int n2 = 0;
   

  cout<<str1<<str2<<endl;

   // printf("\n%d",str[1]);// printing ascii value of '0'

  for(int i=str1.length()-1;i>=0;i--){
    n1 = n1 + (str1[i]-48)*pow(10,str1.length()-1-i);
    cout<<n1<<endl;
   }

   for(int i=str2.length()-1;i>=0;i--){
    n2 = n2 + (str2[i]-48)*pow(10,str2.length()-1-i);
    cout<<n2<<endl;
   }

   cout<<n1*n2<<endl;
   
    
  
  return 0;
}