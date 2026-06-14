/*
Problem: Delete Tail of Doubly Linked List

Approach:
1. Handle empty and single node cases.
2. Traverse to the last node.
3. Disconnect tail from previous node.
4. Delete the tail node.

Time Complexity: O(N)
Space Complexity: O(1)
*/

Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* prevNode = tail->prev;

    prevNode->next = nullptr;
    tail->prev = nullptr;

    delete tail;

    return head;
}
