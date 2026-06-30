/*
## Problem
Given the head of a singly linked list, sort the list in ascending order and return the sorted head.

## Approach
- Use the Merge Sort algorithm, which is well-suited for linked lists.
- Find the middle of the linked list using the slow and fast pointer technique.
- Split the list into two halves.
- Recursively sort both halves.
- Merge the two sorted linked lists into a single sorted list.

## Algorithm
1. If the list has 0 or 1 node, return it.
2. Find the middle node.
3. Split the list into two halves.
4. Recursively sort the left and right halves.
5. Merge the two sorted halves.
6. Return the merged list.

## Time Complexity
- **O(n log n)**

## Space Complexity
- **O(log n)** (recursive call stack)
  */

// Code :-
class Solution {
public:

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left) temp->next = left;
        else temp->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }
};
