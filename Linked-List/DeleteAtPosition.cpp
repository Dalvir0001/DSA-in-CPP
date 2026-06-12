/*
Problem:
Delete a node from a specified position in a singly linked list.

Approach:
1. Handle the case when the list is empty.
2. If position is 1, delete the head node.
3. Traverse the list while maintaining:
   - temp pointer (current node)
   - prev pointer (previous node)
   - cnt variable (current position)
4. When cnt reaches the target position:
   - Link prev to temp->next
   - Delete temp
5. Return the updated head.

Time Complexity: O(n)
Space Complexity: O(1)
*/
// Code :-
Node* deleteAtPosition(Node* head, int k) {
    if(head == nullptr)
        return head;

    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 1;

    while(temp != nullptr) {
        if(cnt == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
        cnt++;
    }

    return head;
}
