#include <bits/stdc++.h>
using namespace std;


vector<int>rm;

int decToBin(int n){
    if(n==0) return 0;
   int rem = n%2;
   rm.push_back(rem);
   n=n/2;//this is quotient
   return decToBin(n);

}

int main(){

int x;
cin>>x;
decToBin(x);
for (auto itr = rm.end()-1; itr >= rm.begin(); --itr)
        cout << *itr;

}