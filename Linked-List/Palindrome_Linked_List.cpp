/*Problem Statement

Given the head of a singly linked list, determine whether the linked list is a palindrome. Return true if it is a palindrome; otherwise, return false.

Approach

To achieve O(n) time and O(1) extra space:

Find the middle of the linked list using the slow and fast pointer technique.
Reverse the second half of the linked list.
Compare nodes from the first half and the reversed second half.
If any pair of nodes differs, the list is not a palindrome.
Restore the original linked list structure by reversing the second half again.
Return the result.
Algorithm
Handle edge cases for empty and single-node lists.
Use slow and fast pointers to locate the middle node.
Reverse the second half starting from slow->next.
Compare corresponding nodes from both halves.
Restore the reversed half before returning.
Return true if all nodes match; otherwise, return false.
Time Complexity
O(n)
Space Complexity
O(1)*/

// Code :-

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head)
    {
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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLinkedList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!=nullptr)
        {
            if(first->val!=second->val)
            {
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newHead);
        return true;
    }
};
