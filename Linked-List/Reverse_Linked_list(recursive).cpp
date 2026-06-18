/*
Problem: Reverse a Singly Linked List (Recursive Approach)

Given the head of a singly linked list, reverse the list and return the new head.

Approach:
1. Recursively reverse the remaining linked list starting from head->next.
2. Once recursion reaches the last node, it becomes the new head.
3. While backtracking:
   - Make the next node point to the current node.
   - Break the original forward link.
4. Return the new head.

Time Complexity: O(n)
Space Complexity: O(n)  // Recursive stack space

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1
*/

// Code :-

class Solution {
  public:
    Node* reverseList(Node* head) {
        if(head==nullptr || head->next==nullptr)
        return head;
        
        Node* newHead = reverseList(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};
