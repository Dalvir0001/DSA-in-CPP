/*
Problem: Sort a Stack
Platform: GeeksforGeeks

Approach:
1. Recursively remove the top element until the stack becomes empty.
2. While recursion backtracks, insert each element into its correct
   position using another recursive function.
3. The recursion call stack acts as the auxiliary stack.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    void insertSorted(stack<int> &st, int x) {
        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertSorted(st, x);

        st.push(temp);
    }

    void sortStack(stack<int> &st) {
        if (st.empty()) return;

        int temp = st.top();
        st.pop();

        sortStack(st);

        insertSorted(st, temp);
    }
};