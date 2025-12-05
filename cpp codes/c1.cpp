// PARANTHESIS CHECKER

#include <bits/stdc++.h>
using namespace std;

bool bracket_checker(string expr)
{
    stack <char> st;

for(int i = 0;i<expr.length();i++)
{
    char ch = expr[i];

    if( ch == '}' || ch == ']' || ch == ')'){
        return false;
    }

    if( ch == '{' || ch == '[' || ch == '(')
    {
        st.push(ch);
    } 
    else if( st.top() == '(' && ch == ')')
    {
        st.pop();
    }
     else if( st.top() == '[' && ch == ']')
    {
        st.pop();
    }
     else if( st.top() == '{' && ch == '}')
    {
        st.pop();
    }
    else{
        return false;
    }

    
}
 
 if(!st.empty()){
 return false;
 }

 return true;
}

int main(){

    string expr = "}[]";

    // Function call
    if (bracket_checker(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
int main(){

    string expr = "}{[]}";

    // Function call
    if (bracket_checker(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}