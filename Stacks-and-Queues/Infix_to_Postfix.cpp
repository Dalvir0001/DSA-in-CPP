/*
Problem: Infix to Postfix
Approach:
- Traverse the infix expression from left to right.
- Append operands directly to the result.
- Push '(' onto the stack.
- On ')', pop operators until '(' is encountered.
- For operators, pop operators with higher precedence,
  or equal precedence (except '^', which is right-associative),
  then push the current operator.
- Pop the remaining operators after traversal.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// Code :-

class Solution {
  public:
    int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] >= 'a' && s[i]<='z' || s[i] >= 'A' && s[i]<='Z' || s[i] >= '0' && s[i]<='9')
            {
                ans.push_back(s[i]);
            }
            else{
                if(st.empty())
                {
                    st.push(s[i]);
                }
                else if(s[i] == '(')
                {
                    st.push(s[i]);
                }
                else if(s[i] == ')')
                {
                    while(st.top()!='(')
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while (!st.empty() && st.top() != '(' &&
                    (precedence(st.top()) > precedence(s[i]) ||
                    (precedence(st.top()) == precedence(s[i]) && s[i] != '^')))
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
