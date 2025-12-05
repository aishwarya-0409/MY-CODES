#include <bits/stdc++.h>
using namespace std;


int fac(int k) {
     
    if (k>1){
    return k*fac(k-1);
    }
    else{
      return 1;
    }
}

int main() {
  int z=fac(5);
  cout<<z;
  
 // return 0;
}
