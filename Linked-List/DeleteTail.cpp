/*
Problem:
Delete the last node from a singly linked list.

Approach:
1. Handle the empty list case.
2. Handle the single-node list case.
3. Traverse the list until reaching the second-last node.
4. Delete the last node.
5. Set the second-last node's next pointer to NULL.

Time Complexity: O(n)
Space Complexity: O(1)
*/
// Code :
Node* deleteLast(Node* head) {
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}
