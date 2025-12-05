#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int fib(int n) {
     
    if (n==2){
    return 1;
    }
    if (n==1){
    return 1;
    }
    if(n==0){
      return 0;
    }
    if(n>2){
      return fib(n-1)+fib(n-2);
    } 
    return 0;
}

int main() {
   auto start = high_resolution_clock::now();
  int z=fib(30);
  cout<<z;
   auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by naive recursive approach: " << duration.count() << " milliseconds" << endl;
    
  return 0;
}
