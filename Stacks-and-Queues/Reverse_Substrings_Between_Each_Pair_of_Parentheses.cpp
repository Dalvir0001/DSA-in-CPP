// Approach:
// Use a stack to store the indexes of opening parentheses.
// Whenever a closing parenthesis is found, reverse the substring
// between the matching pair of parentheses.
// Finally, remove all parentheses and return the resulting string.

// Time Complexity: O(n^2) in the worst case
// Space Complexity: O(n)

// Code :-

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                int start = st.top();
                st.pop();

                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }

        string ans;

        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};