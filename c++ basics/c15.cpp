#include <bits/stdc++.h>
using namespace std;



int main() {
 

    int arr[4] ={1,0,1,1};

    string str ="1011";

    cout<<str[0]<<str[1]<<str[2]<<str[3];

    char* ptr1 = &str[0];
    char* ptr2 = &str[1];
    char* ptr3 = &str[2];

      printf("\n%p\n",ptr1);
      printf("%p\n",ptr2);
      printf("%p",ptr3);

    
  
  return 0;
}