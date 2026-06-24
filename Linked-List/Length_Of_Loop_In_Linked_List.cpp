/*
Problem Statement

Given the head of a linked list, determine whether the linked list contains a loop. If a loop exists, return the length of the loop; otherwise, return 0.

Approach

This solution uses Floyd's Cycle Detection Algorithm (Tortoise and Hare Algorithm).

Initialize two pointers, slow and fast, at the head.
Move slow by one step and fast by two steps.
If slow and fast meet, a cycle exists.
To find the loop length:
Keep one pointer fixed.
Move the other pointer around the cycle until it reaches the fixed pointer again.
Count the number of nodes traversed.
Return the count as the length of the loop.
If no cycle is found, return 0.
Time Complexity
O(N)
Space Complexity
O(1)
*/

// Code :-

class Solution {
public:
    int lengthOfLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                int count = 1;
                fast = fast->next;

                while (slow != fast) {
                    fast = fast->next;
                    count++;
                }

                return count;
            }
        }

        return 0;
    }
};
