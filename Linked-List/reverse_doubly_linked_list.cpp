/*Reversed a Doubly Linked List using an iterative approach. The solution swaps the next and prev pointers of each node while traversing the list. After all pointers are reversed, the last processed node becomes the new head of the list.

Approach:
1. Traverse the doubly linked list.
2. Swap the next and prev pointers for each node.
3. Move to the original next node using the updated prev pointer.
4. Return the new head after completion.

Time Complexity: O(N)
Space Complexity: O(1)
  */

//Code :-

class Solution {
  public:
    Node *reverse(Node *head) {
        if(head==nullptr || head->next==nullptr) return head;
        Node* curr = head;
        Node* prev = nullptr;
        while(curr!=nullptr)
        {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        return prev->prev;
    }
};
