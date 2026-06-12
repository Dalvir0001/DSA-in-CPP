/*
Problem:
Insert a new node at the beginning of a singly linked list.

Approach:
1. Create a new node with the given value.
2. Make the new node point to the current head.
3. Update head to the new node.
4. Return the updated head.

Time Complexity: O(1)
Space Complexity: O(1)
*/
//Code
Node* insertAtFront(Node* head, int x) {
    Node* newNode = new Node(x);

    newNode->next = head;
    head = newNode;

    return head;
}
