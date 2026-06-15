/*Reverse Linked List (LeetCode 206)
Problem Statement

Given the head of a singly linked list, reverse the list and return the reversed list.

Approach

This solution uses an iterative three-pointer approach:

back stores the previous node.
curr stores the current node being processed.
front temporarily stores the next node.

For each node:

Store the next node in front.
Reverse the current node's link.
Move back and curr one step forward.

After the traversal, back points to the new head of the reversed linked list.*/

// Code :-
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* back =nullptr;
        ListNode* curr = head;
        while(curr!=nullptr) 
        {
            ListNode* front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
        }
        return back;
    }
};
