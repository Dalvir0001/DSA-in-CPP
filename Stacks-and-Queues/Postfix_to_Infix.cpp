/*
Problem: Postfix to Infix Conversion
Approach:
- Traverse the postfix expression.
- Push operands as strings onto the stack.
- When an operator is encountered:
    1. Pop the top two strings.
    2. Form "(operand2 operator operand1)".
    3. Push the resulting expression back.
- The final stack element is the required infix expression.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// Code :-

class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string> st;
        int i = 0;
        while(i<exp.size())
        {
            if(exp[i] >= 'a' && exp[i]<='z' || exp[i] >= 'A' && exp[i]<='Z' || exp[i] >= '0' && exp[i]<='9')
            {
                char ch = exp[i];
                st.push(string(1, ch));
                
            }
            else{
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                st.push('('+second+exp[i]+first+')');
            }
            i++;
        }
        return st.top();
    }
};