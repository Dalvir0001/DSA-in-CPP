/*
    Approach:
    1. Push all people into a stack.
    2. Pop two people at a time and eliminate one candidate:
       - If A knows B, then A cannot be the celebrity.
       - Otherwise, B cannot be the celebrity.
    3. After all eliminations, only one candidate remains.
    4. Verify whether the remaining candidate:
       - Knows nobody.
       - Is known by everyone.
    5. If both conditions are satisfied, return the candidate's index;
       otherwise, return -1.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

// Code :-

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n= mat.size();
        stack<int> st;
        for(int i=0 ; i<n ; i++)
        st.push(i);
        while(st.size()>1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(mat[a][b] == 1)
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        int top = st.top();
        for(int i=0 ; i<n ; i++)
        {
            if((mat[top][i] == 1 || mat[i][top] == 0) && top!=i)
            return -1;
        }
        return top;
    }
};