// ## 239. Sliding Window Maximum

// - **Approach:** Monotonic Deque
// - **Time Complexity:** O(n)
// - **Space Complexity:** O(k)

// ### Key Idea
// Maintain a deque of indices in decreasing order of their values.
// - Remove indices that are outside the current window.
// - Remove smaller elements from the back before inserting the current element.
// - The front of the deque always stores the index of the maximum element in the current window.

// Code :-

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};