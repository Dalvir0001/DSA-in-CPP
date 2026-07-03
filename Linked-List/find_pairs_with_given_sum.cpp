/*
## Find Pairs with Given Sum in a Doubly Linked List

### Approach
- Since the doubly linked list is sorted, use the two-pointer technique.
- Initialize one pointer at the head and another at the tail.
- Compare the sum of both pointers with the target:
  - If the sum equals the target, store the pair and move both pointers.
  - If the sum is smaller, move the left pointer forward.
  - If the sum is larger, move the right pointer backward.
- Continue until the pointers meet or cross.

### Time Complexity
- O(n)

### Space Complexity
- O(1) (excluding the output vector)

*/

// Code :-

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        vector<pair<int, int>> ans;
        if (head == NULL) return ans;

        Node *left = head;
        Node *right = head;

        // Move right to the last node
        while (right->next != NULL) {
            right = right->next;
        }

        // Two-pointer traversal
        while (left != right && left->prev != right) {

            int sum = left->data + right->data;

            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};
