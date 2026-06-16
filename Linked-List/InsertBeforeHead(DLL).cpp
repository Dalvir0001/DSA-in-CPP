/*
## Insert Before Head

### Intuition

To insert a node before the head, create a new node and make it point to the current head. Then update the current head's back pointer to the new node.

### Steps

1. Create a new node.
2. Set its next pointer to the current head.
3. Update head->back to the new node.
4. Return the new node as the new head.

### Complexity

* Time Complexity: O(1)
* Space Complexity: O(1)
*/
//Code:-
Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);

    if (head != nullptr) {
        head->back = newHead;
    }

    return newHead;
}
