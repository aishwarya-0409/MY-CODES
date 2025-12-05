//  Reverse a String using Stack

#include <bits/stdc++.h>
using namespace std;

void stck(string expr){
    
    stack <char> st;

    for(int i = 0;i<expr.length();i++)
{
    char ch = expr[i];
     
      if( ch == '+' || ch == '-' || ch == '*'|| ch == '/' )
    { 
      
    } 
    else{
      st.push(ch);
      cout<<st.top();
    }
}



}

int main(){

string expr = "A+B";

stck(expr);

return 0;

}
