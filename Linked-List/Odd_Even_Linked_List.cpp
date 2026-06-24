/*
Problem Statement

Given the head of a singly linked list, group all nodes with odd indices together followed by the nodes with even indices, while maintaining their relative order.

The first node is considered odd, the second node even, and so on.

Approach

This solution uses two pointers to maintain separate odd-indexed and even-indexed lists.

Initialize odd at the head node and even at the second node.
Store the head of the even list in evenHead.
Traverse the list and connect odd nodes together.
Similarly, connect even nodes together.
Attach the even list after the odd list.

This rearranges the list in-place without using any extra data structure.

Algorithm
Handle edge cases for lists with fewer than three nodes.
Maintain pointers:
odd for odd-indexed nodes.
even for even-indexed nodes.
evenHead to remember the start of the even list.
Update links to separate odd and even nodes.
Connect the last odd node to evenHead.
Return the modified head.
Example

Input:
1 → 2 → 3 → 4 → 5

Odd nodes:
1 → 3 → 5

Even nodes:
2 → 4

Output:
1 → 3 → 5 → 2 → 4

Time Complexity
O(n)
Space Complexity
O(1)
*/

// Code :-

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(odd->next!=nullptr && odd->next->next!=nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
