/*
Problem:
Delete the first occurrence of a given value from a singly linked list.

Approach:
1. Handle the empty list case.
2. If the head node contains the value, delete the head.
3. Traverse the list using temp and prev pointers.
4. When the target value is found:
   - Link prev to temp->next.
   - Delete temp.
5. Return the updated head.

Time Complexity: O(n)
Space Complexity: O(1)
*/
// Code :-

Node* deleteByValue(Node* head, int value) {
    if(head == nullptr)
        return head;

    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr) {
        if(temp->data == value) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
