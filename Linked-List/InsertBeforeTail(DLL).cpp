/*
## Insert Before Tail

### Intuition

First reach the tail node. Then create a new node and place it between the tail and the node before the tail.

### Steps

1. Traverse to the tail.
2. Store the node before tail.
3. Create a new node.
4. Connect previous node to the new node.
5. Connect new node to tail.

### Complexity

* Time Complexity: O(N)
* Space Complexity: O(1)
*/

// Code :-
Node* insertBeforeTail(Node* head, int val) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        return insertBeforeHead(head, val);
    }

    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* prev = tail->back;

    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}
