/*
Approach:
- Traverse the doubly linked list using a temporary pointer.
- Whenever a node with value x is found:
  - Update the head if the node is the first node.
  - Link the previous node to the next node.
  - Link the next node back to the previous node.
  - Delete the current node.
- Continue until the end of the list.

Time Complexity: O(n)
Space Complexity: O(1)
  */

// Code :-

class Solution {
public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == x) {
                if (temp == head)
                    head = head->next;

                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;

                if (nextNode)
                    nextNode->prev = prevNode;

                if (prevNode)
                    prevNode->next = nextNode;

                delete temp;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
