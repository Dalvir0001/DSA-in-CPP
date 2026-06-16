/*
Intuition

When the target node is already given, no traversal is needed. Simply place the new node between the target node and its previous node.

Steps

Store the previous node.
Create a new node.
Connect previous node to new node.
Connect new node to target node.
Update backward links.

Complexity

Time Complexity: O(1)
Space Complexity: O(1)

*/

// Code :-
void insertBeforeGivenNode(Node* node, int val) {
    Node* prev = node->back;

    Node* newNode = new Node(val, node, prev);

    prev->next = newNode;
    node->back = newNode;
}
