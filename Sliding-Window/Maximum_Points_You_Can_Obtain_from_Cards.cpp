/*
    Maximum Points You Can Obtain from Cards

    Intuition:
    There are only (k + 1) possible ways to pick k cards:
    Take 0 from left & k from right,
    Take 1 from left & (k-1) from right,
    ...
    Take k from left & 0 from right.

    Algorithm:
    1. Calculate the sum of the first k cards.
    2. Move one card at a time from the left selection to the right selection.
    3. Update the maximum score after each move.

    Time Complexity: O(k)
    Space Complexity: O(1)
*/

// Code :-

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0; i<k ; i++)
        {
            sum+=cardPoints[i];
        }
        int left = k-1;
        int right = n-1;
        int curr = sum ;
        while(left>=0)
        {
            curr -= cardPoints[left];
            curr += cardPoints[right];
            sum = max(sum,curr);
            left--;
            right--;
        }
        return sum;
    }
};