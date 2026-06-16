/*
## Insert Before K-th Position (1 based indexing)

### Intuition

Traverse to the K-th node and insert the new node just before it by adjusting four pointers.

### Steps

1. If K = 1, insert before head.
2. Reach the K-th node.
3. Store its previous node.
4. Create a new node.
5. Update the links:

   * previous -> new node
   * new node -> K-th node
   * K-th node -> back to new node

### Complexity

* Time Complexity: O(N)
* Space Complexity: O(1)
*/

//Code :-
Node* insertBeforeKthPosition(Node* head, int k, int val) {
    if (k == 1) {
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 1;

    while (temp != nullptr) {
        cnt++;

        if (cnt == k) {
            break;
        }

        temp = temp->next;
    }

    Node* prev = temp->back;

    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}
