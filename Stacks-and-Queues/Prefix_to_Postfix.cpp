/*
 * Problem: Convert Prefix Expression to Postfix Expression
 * Approach:
 *   - Traverse the prefix string from RIGHT to LEFT using a Stack.
 *   - If the character is an operand (letter/digit), push it onto the stack.
 *   - If the character is an operator:
 *       1. Pop the top element as the left operand (op1).
 *       2. Pop the next element as the right operand (op2).
 *       3. Combine them as: op1 + op2 + Operator
 *       4. Push the combined string back onto the stack.
 *   - The top of the stack will contain the final Postfix expression.
 *
 * Time Complexity:  O(N) - single right-to-left pass through the string
 * Space Complexity: O(N) - stack storage for sub-expressions
 */

 // Code:-

 class Solution {
  public:
    string preToPost(string &s) {
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
                st.push(first+second+s[i]);
            }
            i--;
        }
        return st.top();
    }
};