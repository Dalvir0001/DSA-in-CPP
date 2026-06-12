/*
Problem:
Insert a new node at the end of a singly linked list.

Approach:
1. Create a new node with the given value.
2. If the list is empty, return the new node as head.
3. Traverse the list until the last node.
4. Connect the last node to the new node.
5. Return the head of the updated list.

Time Complexity: O(n)
Space Complexity: O(1)
*/

// Code :-
Node* insertAtLast(Node* head, int x) {
    Node* newNode = new Node(x);

    if(head == nullptr)
        return newNode;

    Node* temp = head;

    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}
