/*
Approach: Monotonic Stack

1. Maintain a monotonic decreasing stack that stores the indices of the bars.
2. Traverse the height array from left to right.
3. If the current bar is shorter than or equal to the bar at the top of the stack,
   push its index onto the stack.
4. If the current bar is taller, it forms the right boundary of a valley.
5. Pop the stack to get the bottom of the valley.
6. If the stack becomes empty, no left boundary exists, so continue.
7. Otherwise:
      - Left Boundary  = st.top()
      - Right Boundary = current index
      - Width          = right - left - 1
      - Height         = min(height[left], height[right]) - height[bottom]
8. Add (Width × Height) to the total trapped water.
9. Push the current index and continue the traversal.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// Code :-

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int total = 0;

        for (int i = 0; i < height.size(); i++) {

            while (!st.empty() && height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                if (st.empty())
                    break;

                int left = st.top();

                int width = i - left - 1;

                int boundedHeight = min(height[left], height[i]) - height[bottom];

                total += width * boundedHeight;
            }

            st.push(i);
        }

        return total;
    }
};