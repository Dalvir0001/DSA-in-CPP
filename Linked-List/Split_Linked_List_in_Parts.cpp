/*
# Split Linked List in Parts

## Problem
Split a linked list into `k` consecutive parts such that the sizes of the parts differ by at most one. Earlier parts should have at most one extra node compared to later parts.

## Approach
1. Find the length of the linked list.
2. Calculate the base size of each part using division (`length / k`).
3. Distribute the remaining nodes (`length % k`) among the first few parts.
4. Traverse the list and split it into `k` consecutive parts by updating the `next` pointers.

## Algorithm Used
- Linked List
- Pointer Manipulation
- Division & Remainder

## Time Complexity
- **O(n)**

## Space Complexity
- **O(1)** (excluding the output vector)

*/

// Code :-

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int len = 0;
        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        int partSize = len / k;
        int extra = len % k;

        vector<ListNode*> ans(k, nullptr);

        temp = head;

        for (int i = 0; i < k && temp; i++) {

            ans[i] = temp;

            int currSize = partSize + (extra > 0 ? 1 : 0);
            extra--;

            for (int j = 1; j < currSize; j++)
                temp = temp->next;

            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }

        return ans;
    }
};
