#include <bits/stdc++.h>
using namespace std;



int main() {
    for (int i = 1; i <= 5; ++i) {     
        for (int j = 5-i; j > 0; j--) {
          cout<<" ";
          } 
        //for(int k = 1;k<=i;++k){
          for(int l = 1;l<= i;++l) {
            cout<<"* ";
          }
       // }
    cout<<endl;
  }
  return 0;

   
}
