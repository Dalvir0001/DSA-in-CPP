/*
Approach:
- Solved the problem by treating each row as the base of a histogram.
- Maintained a height array where each element stores the consecutive number
  of '1's ending at the current row.
- For every row, updated the histogram and reused the Largest Rectangle in
  Histogram (LeetCode 84) algorithm using a monotonic increasing stack.
- The maximum rectangle area across all histograms is the final answer.

Algorithm:
1. Initialize a height array with all zeros.
2. For each row:
   - Increment height[j] if matrix[i][j] == '1'.
   - Otherwise, reset height[j] to 0.
3. Compute the largest rectangle in the current histogram.
4. Update the overall maximum area.

Time Complexity: O(rows × cols)
Space Complexity: O(cols)
*/

// Code :-

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = INT_MIN;
        for(int i =0  ; i < heights.size() ; i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(),0);
        int maxi = 0;
        for(int i=0 ; i<matrix.size() ; i++)
        {
            for(int j=0;  j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                {
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            int current = largestRectangleArea(heights);
            maxi = max(current,maxi);
        }
        return maxi;
    }
};