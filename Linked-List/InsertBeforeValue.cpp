/*
Problem:
Insert a new node before the first occurrence of a given value
in a singly linked list.

Approach:
1. If the list is empty, return NULL.
2. If the head contains the target value, create a new node and
   make it the new head.
3. Traverse the list until the next node contains the target value.
4. Create a new node and insert it before the target node.
5. Return the updated head.

Time Complexity: O(n)
Space Complexity: O(1)
*/
//Code:-
Node* insertBeforeValue(Node* head, int el, int val) {
    
    if(head == NULL) return NULL;

    if(head->data == val) {
        return new Node(el, head);
    }

    Node* temp = head;

    while(temp->next != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
}
