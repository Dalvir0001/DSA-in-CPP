/*
Approach:
- Use the "At Most Sliding Window" technique.
- Count the number of subarrays with sum at most(goal).
- Count the number of subarrays with sum at most(goal - 1).
- The difference between these two counts gives the number of subarrays
  having sum exactly equal to the goal.

Time Complexity: O(n)
Space Complexity: O(1)
*/

// Code :-

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int left = 0;
        int sum = 0;
        int cnt = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left++];
            }

            cnt += right - left + 1;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};