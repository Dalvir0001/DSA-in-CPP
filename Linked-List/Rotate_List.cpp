/*
    Problem: Rotate List
    Platform: LeetCode
    Problem No.: 61

    Approach:
    - Find the length of the linked list.
    - Reduce rotations using k %= length.
    - Connect the tail to the head to form a circular linked list.
    - Find the new last node at position (length - k).
    - Break the circular link and return the new head.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

// Code :-

class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != nullptr) {
            if (cnt == k)
                return temp;
            cnt++;
            temp = temp->next;
        }
        return nullptr;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* tail = head;
        int len = 1;

        while (tail->next != nullptr) {
            len++;
            tail = tail->next;
        }

        k %= len;
        if (k == 0)
            return head;

        tail->next = head;

        ListNode* newLastNode = findNthNode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }
};
