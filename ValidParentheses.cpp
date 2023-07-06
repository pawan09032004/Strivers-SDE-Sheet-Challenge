#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for(auto i:expression){
        if(i=='{' || i=='(' || i=='[')
            st.push(i);
        else if(!st.empty()){
            char t= st.top();
            if((t=='{'&& i=='}') || (t=='(' && i==')') || (t=='[' && i==']')){
                st.pop();
            }
            else return false;
        }
        else return false;
    }
    return st.empty();
}
