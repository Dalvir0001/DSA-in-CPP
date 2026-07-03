/*
# Reverse Nodes in k-Group

## Problem
Reverse the nodes of a linked list in groups of size `k`. If the number of remaining nodes is less than `k`, leave them as they are.

## Approach
- Traverse the linked list group by group.
- Find the kth node of the current group.
- Detach the group from the remaining list.
- Reverse the current group using an iterative linked list reversal.
- Connect the reversed group with the previous and next parts of the list.
- Repeat until all possible groups are processed.

## Algorithms Used
- Linked List
- Iterative Pointer Manipulation
- Group-wise Reversal

## Time Complexity
**O(n)**

## Space Complexity
**O(1)**
*/

// Code :-

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
    ListNode* findKthNode(ListNode* temp , int k)
    {
        k -= 1;
        while(temp != nullptr && k>0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while(temp != nullptr)
        {
            ListNode* kthNode = findKthNode(temp , k);
            if(kthNode == nullptr)
            {
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseList(temp);
            if(temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
