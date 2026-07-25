/*
 * Problem: Convert Postfix Expression to Prefix Expression
 * Approach:
 *   - Iterate through the postfix string from left to right using a Stack.
 *   - If the character is an operand (letter/digit), push it onto the stack.
 *   - If the character is an operator:
 *       1. Pop the top element as the right operand (op2).
 *       2. Pop the next element as the left operand (op1).
 *       3. Combine them as: Operator + op1 + op2
 *       4. Push the combined string back onto the stack.
 *   - The top of the stack will contain the final Prefix expression.
 *
 * Time Complexity:  O(N) - single pass through the string
 * Space Complexity: O(N) - stack storage for sub-expressions
 */

 // Code :-

 class Solution {
  public:
    string postToPre(string s) {
        stack<string> st;
        int i = 0;
        while(i<s.size())
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
                st.push(s[i]+second+first);
            }
            i++;
        }
        return st.top();
    }
};