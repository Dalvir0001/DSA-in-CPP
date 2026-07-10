/*
Problem: Reverse a Stack
Platform: GeeksforGeeks

Approach:
1. Recursively remove all elements from the stack.
2. Insert each removed element at the bottom of the stack using another recursive function.
3. The recursion call stack acts as the auxiliary stack, resulting in the stack being reversed.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

// Code :- 

class Solution {
  public:
    void insertAtBottom(stack<int> &st , int x)
    {
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int temp = st.top();
        st.pop();
        
        insertAtBottom(st , x);
        
        st.push(temp);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
         int temp = st.top();
         st.pop();
         
         reverseStack(st);
         
         insertAtBottom(st,temp);
    }
};