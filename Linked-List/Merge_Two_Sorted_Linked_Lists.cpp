/*
Problem: Merge two sorted linked lists into a single sorted linked list.

Approach:

Create a dummy node to simplify handling the head of the merged list.
Maintain two pointers (t1 and t2) for the two input lists.
Compare the current nodes of both lists.
Append the smaller node to the merged list and move the corresponding pointer forward.
After one list is exhausted, attach the remaining nodes of the other list.
Return dummy->next as the head of the merged list.

Time Complexity: O(N + M)

N = number of nodes in the first list
M = number of nodes in the second list

Space Complexity: O(1)

No extra space is used apart from the dummy node.
*/

// Code :-
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* dmNode = new Node(-1);
        Node* temp = dmNode;
        Node* t1 = head1;
        Node* t2 = head2;
        while(t1!=nullptr && t2!=nullptr)
        {
            if(t1->data < t2->data)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if(t1) temp->next=t1;
        else temp->next=t2;
        return dmNode->next;
    }
};
