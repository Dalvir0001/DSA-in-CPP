/*
Problem: Linked List Cycle (LeetCode 141)

Approach:
- Use two pointers: slow and fast.
- Move slow by one node and fast by two nodes in each iteration.
- If a cycle exists, the two pointers will eventually meet.
- If fast or fast->next becomes null, the linked list does not contain a cycle.

Time Complexity: O(n)
Space Complexity: O(1)

Concepts Used:
- Linked List
- Two Pointers
- Floyd's Cycle Detection Algorithm
- Fast and Slow Pointer Technique
*/

// Code :-

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
