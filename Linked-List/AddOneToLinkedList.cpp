/*
Problem: Add 1 to a Number Represented as a Linked List

Approach (Recursive):

Recursively traverse to the last node.
Return a carry of 1 from the base case (nullptr).
While returning from recursion, add the carry to each node.
If a node becomes 10, set it to 0 and propagate the carry.
If a carry remains after processing the head, create a new node with value 1.

Complexity:

Time: O(n)
Space: O(n) (recursive call stack)
  */

// Code :-

class Solution {
public:
    int addHelper(Node* temp) {
        if (temp == nullptr)
            return 1;

        int carry = addHelper(temp->next);

        temp->data += carry;

        if (temp->data < 10)
            return 0;

        temp->data = 0;
        return 1;
    }

    Node* addOne(Node* head) {
        int carry = addHelper(head);

        if (carry) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }

        return head;
    }
};
