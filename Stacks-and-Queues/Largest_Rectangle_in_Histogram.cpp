/*
Approach:
- Solved using a monotonic increasing stack in O(n) time.
- Each bar is treated as the smallest height of a potential rectangle.
- Whenever a smaller bar is encountered, bars are popped from the stack,
  and the maximum rectangle area is calculated using:
      width = Next Smaller Index - Previous Smaller Index - 1
      area = height * width
- Remaining bars in the stack are processed after the traversal.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// Code :-

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = INT_MIN;
        for(int i =0  ; i < heights.size() ; i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxi = max(heights[element]*(nse-pse-1),maxi);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int element = st.top();
            st.pop();
            int nse = heights.size();
            int pse = st.empty()?-1:st.top();
            maxi = max(heights[element]*(nse-pse-1),maxi);
        }
        return maxi;
    }
};