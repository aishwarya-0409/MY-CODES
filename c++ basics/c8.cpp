#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<int>fb;

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
    if(fb[n]!=0){
      return fb[n];
    }
    if(n>2){
      fb[n] = fib(n-1)+fib(n-2);
      return fb[n];
    } 
    return 0;
}


int main() {
  int n = 30;
 
   for(int i=0;i<=n;i++){
    fb.push_back(0);
  }
  //fb = vector<int>(n + 1, 0); // Initialize the fb vector with n+1 elements, all set to 0
auto start = high_resolution_clock::now();
   int z=fib(n);
  cout<<z;
  auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by naive recursive approach: " << duration.count() << " milliseconds" << endl;
    
 for(int i=0;i<=n;i++){
    cout<<fb[i]<<" ";
  }
  return 0;
}
