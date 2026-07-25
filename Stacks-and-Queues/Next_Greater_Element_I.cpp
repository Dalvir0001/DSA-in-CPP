/*
Next Greater Element I

Approach:
- Traverse nums2 from right to left.
- Use a monotonic decreasing stack to find the next greater element for every number.
- Store the mapping (element -> next greater element) in an unordered_map.
- Build the answer for nums1 using the map.

Time Complexity: O(n + m)
Space Complexity: O(n)
*/

// Code :-
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i = nums2.size()-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty()) 
            {
                mpp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            else{
                mpp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }
        for(int i= 0 ; i<nums1.size() ; i++)
        {
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};