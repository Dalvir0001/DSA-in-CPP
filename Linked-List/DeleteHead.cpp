/*
Problem: Delete the first node of a singly linked list.

Approach:
1. Store the current head node.
2. Move head to the next node.
3. Delete the old head node.
4. Return the new head.

Time Complexity: O(1)
Space Complexity: O(1)
*/

Node* deleteHead(Node* head) {
    if(head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}
