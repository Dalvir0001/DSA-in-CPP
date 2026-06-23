/*
Problem: Linked List Cycle II (LeetCode 142)

Approach:
- Use Floyd's Cycle Detection Algorithm with two pointers: slow and fast.
- First, detect whether a cycle exists by moving slow one step and fast two steps.
- If the pointers meet, reset slow to the head of the list.
- Move both pointers one step at a time until they meet again.
- The meeting point is the starting node of the cycle.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                slow = head ; 
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
