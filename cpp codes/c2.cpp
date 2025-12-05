//  Reverse a String using Stack

#include <bits/stdc++.h>
using namespace std;

void stck(string expr){
    
    stack <char> st;

    for(int i = 0;i<expr.length();i++)
{
    char ch = expr[i];
      st.push(ch);
}


while (!st.empty()){
    cout<<st.top();
  st.pop();
}


}

int main(){

string expr = "Aishwarya";

stck(expr);

return 0;

}
