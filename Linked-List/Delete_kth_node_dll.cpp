/*
Problem: Delete K-th Node of Doubly Linked List

Approach:
1. Traverse to the K-th node.
2. Handle head, tail and single node cases separately.
3. Connect previous and next nodes.
4. Delete the K-th node.

Time Complexity: O(N)
Space Complexity: O(1)
*/

Node* deleteKthNode(Node* head, int k) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    int cnt = 1;

    while (temp != nullptr) {
        if (cnt == k) break;

        cnt++;
        temp = temp->next;
    }

    if (temp == nullptr) return head;

    Node* back = temp->prev;
    Node* front = temp->next;

    if (back == nullptr && front == nullptr) {
        delete temp;
        return nullptr;
    }

    if (back == nullptr) {
        head = front;
        front->prev = nullptr;

        temp->next = nullptr;
        delete temp;

        return head;
    }

    if (front == nullptr) {
        back->next = nullptr;

        temp->prev = nullptr;
        delete temp;

        return head;
    }

    back->next = front;
    front->prev = back;

    temp->next = nullptr;
    temp->prev = nullptr;

    delete temp;

    return head;
}
