/*
Problem: Delete Given Node in Doubly Linked List

Approach:
1. Access previous and next nodes.
2. Update links between them.
3. Delete the given node.

Time Complexity: O(1)
Space Complexity: O(1)
*/

void deleteNode(Node* temp) {
    if (temp == nullptr) return;

    Node* back = temp->prev;
    Node* front = temp->next;

    if (front == nullptr) {
        back->next = nullptr;
        temp->prev = nullptr;

        delete temp;
        return;
    }

    back->next = front;
    front->prev = back;

    temp->next = nullptr;
    temp->prev = nullptr;

    delete temp;
}
