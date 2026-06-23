/*
Problem: Middle of the Linked List (LeetCode 876)

Approach:
- Use two pointers: slow and fast.
- Move slow by one node and fast by two nodes in each iteration.
- When fast reaches the end of the list, slow will be at the middle node.
- If the list has an even number of nodes, the second middle node is returned.

Time Complexity: O(n)
Space Complexity: O(1)

Concepts Used:
- Linked List
- Two Pointers
- Slow and Fast Pointer Technique
*/
//Code

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
  }
};
