/*
 * Problem: Prefix to Infix Conversion
 * Time Complexity: O(N) - Single pass through the string of length N
 * Space Complexity: O(N) - Stack used to store expressions
 * 
 * Approach:
 * 1. Traverse the prefix expression from right to left (end to start).
 * 2. If the character is an operand (letter/digit), push it onto the stack.
 * 3. If the character is an operator:
 *    - Pop the top two elements from the stack (op1, op2).
 *    - Combine them into the infix form: "(" + op1 + operator + op2 + ")"
 *    - Push the resulting string back onto the stack.
 * 4. After processing all characters, the top of the stack contains the final infix string.
 */

class Solution {
  public:
    string preToInfix(string &s) {
        stack<string> st;
        int i = s.size()-1;
        while(i>=0)
        {
            if(s[i] >= 'a' && s[i]<='z' || s[i] >= 'A' && s[i]<='Z' || s[i] >= '0' && s[i]<='9')
            {
                char ch = s[i];
                st.push(string(1, ch));
                
            }
            else{
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                st.push('('+first+s[i]+second+')');
            }
            i--;
        }
        return st.top();
    }
};