/*
Problem    : Delete the Middle Node of a Linked List
Platform   : LeetCode
Difficulty : Medium
Approach   : Fast & Slow Pointer (Two Pointers)
Time       : O(N)
Space      : O(1)

Description:
- Handle the edge case where the list has only one node.
- Use two pointers: slow and fast.
- Move fast by two steps and slow by one step.
- When fast reaches the end, slow points to the node
  just before the middle node.
- Update the links to remove the middle node and free
  its memory.
*/

// Code :-

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middleNode = slow->next;
        slow->next = slow->next->next;
        delete middleNode;
        return head;
    }
};
