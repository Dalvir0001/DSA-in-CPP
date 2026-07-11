/*
## 20. Valid Parentheses

### Approach
- Use a stack to keep track of opening brackets.
- Push every opening bracket onto the stack.
- For every closing bracket, check whether it matches the top of the stack.
- If the stack is empty or the brackets don't match, return false.
- At the end, if the stack is empty, the parentheses are valid.

### Time Complexity
- O(n)

### Space Complexity
- O(n)
*/

// Code :-

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char temp = st.top();
                st.pop();
                if((temp == '(' && s[i] != ')') || temp == '[' && s[i] != ']' || temp == '{' && s[i] != '}')
                return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};