/*
Problem:
Insert a new node at a specified position in a singly linked list.

Approach:
1. If k = 1, insert the new node at the beginning.
2. Traverse the list until reaching the (k-1)th node.
3. Create a new node with the given value.
4. Link the new node to the kth node.
5. Update the (k-1)th node to point to the new node.
6. Return the updated head.

Time Complexity: O(n)
Space Complexity: O(1)
*/

//Code :-
Node* insertAtPosition(Node* head, int k, int val) {
    if(k == 1) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int cnt = 1;

    while(temp != nullptr) {
        if(cnt == k - 1) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }

        temp = temp->next;
        cnt++;
    }

    return head;
}
