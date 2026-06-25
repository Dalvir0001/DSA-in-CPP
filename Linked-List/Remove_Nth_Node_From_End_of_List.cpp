/*
Problem    : Remove Nth Node From End of List
Platform   : LeetCode
Difficulty : Medium
Approach   : Two Pointers (Fast & Slow Pointer)
Time       : O(N)
Space      : O(1)

Description:
- Move the fast pointer n steps ahead.
- If fast becomes nullptr, remove the head node.
- Otherwise, move both fast and slow pointers together
  until fast reaches the last node.
- Delete the nth node from the end by updating pointers.
  */

// Code :-

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0 ; i<n ; i++)
        {
            fast = fast->next;
        }
        if(fast==nullptr) return head->next;
        while(fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
