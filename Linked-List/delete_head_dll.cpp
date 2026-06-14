/*
Problem: Delete Head of Doubly Linked List

Approach:
1. Handle empty list.
2. Handle single node list.
3. Move head to next node.
4. Update prev pointer of new head.
5. Delete old head node.

Time Complexity: O(1)
Space Complexity: O(1)
*/

// Code :-
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;

    head->prev = nullptr;
    temp->next = nullptr;

    delete temp;

    return head;
}
