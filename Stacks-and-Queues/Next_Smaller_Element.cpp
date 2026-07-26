/*
    Monotonic Stack Approach

    Traverse the array from right to left while maintaining
    an increasing stack. Pop all elements greater than or
    equal to the current element. The stack's top is the
    next smaller element.

    Time: O(n)
    Space: O(n)
*/

// Code :-

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        vector<int> ans(arr.size() , -1);
        stack<int> st;
        for(int i = arr.size()-1 ; i>=0 ; i--)
        {
            while(!st.empty() && st.top()>=arr[i]) st.pop();
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};