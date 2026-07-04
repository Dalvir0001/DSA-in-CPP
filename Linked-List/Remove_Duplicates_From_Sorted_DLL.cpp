/*
Problem
Remove Duplicates from a Sorted Doubly Linked List

Approach
Traverse the doubly linked list using a single pointer (curr).
Compare the current node with its next node.
If both nodes contain the same value:
Remove the duplicate node by updating the next pointer of the current node.
Update the prev pointer of the following node (if it exists).
Delete the duplicate node to free memory.
Otherwise, move to the next node.
Continue until the end of the list.

Algorithm
Initialize curr as the head of the list.
Traverse while curr and curr->next are not nullptr.
If curr->data == curr->next->data:
Store the duplicate node.
Update links to bypass the duplicate.
Fix the prev pointer of the next node.
Delete the duplicate node.
Otherwise, move curr to the next node.
Return the modified head.
  
Complexity
Time Complexity: O(n)
Space Complexity: O(1)
*/

// Code :-

class Solution {
public:
    Node* removeDuplicates(Node* headRef) {
        if(headRef == nullptr) return headRef;

        Node* curr = headRef;

        while(curr != nullptr && curr->next != nullptr)
        {
            if(curr->data == curr->next->data)
            {
                Node* temp = curr->next;
                curr->next = temp->next;

                if(temp->next != nullptr)
                    temp->next->prev = curr;

                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }

        return headRef;
    }
};
