/*
## Problem
Given the heads of two singly linked lists, return the node at which the two lists intersect. If the two linked lists have no intersection, return `null`.

## Approach
- Use two pointers, one starting at the head of each linked list.
- Traverse both lists simultaneously.
- When a pointer reaches the end of its list, redirect it to the head of the other list.
- After at most two traversals, both pointers will either meet at the intersection node or both become `null` if no intersection exists.

## Algorithm
1. Initialize two pointers `t1` and `t2` at the heads of the two linked lists.
2. Move both pointers one step at a time.
3. If a pointer reaches the end of its list, redirect it to the head of the other list.
4. Continue until both pointers are equal.
5. Return the intersection node (or `null` if no intersection exists).

## Time Complexity
- **O(n + m)**

## Space Complexity
- **O(1)**
*/

// Code :-

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1==t2) return t1;
            if(t1==nullptr) t1 =  headB;
            if(t2==nullptr) t2 =  headA;
        }
        return t1;
    }
};
