/*
Problem
Copy List with Random Pointer

Approach
Create a copy of each node and insert it immediately after its original node.
Traverse the modified list and assign the random pointer of each copied node using the original node's random pointer.
Separate the copied nodes from the original list while restoring the original list structure.
Return the head of the deep copied linked list.
  
Algorithm
Insert a copy node after every original node.
Set the random pointer of each copy node:
If the original node has a random pointer, point the copy node's random to original->random->next.
Extract the copied list while restoring the original list.
Return the head of the copied list.
  
Complexity
Time Complexity: O(n)
Space Complexity: O(1) (excluding the space required for the copied nodes)
*/

// Code :-

class Solution {
public:
    void InsertCopyInBetween(Node* head)
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            Node* nextElement = temp->next;
            Node* copyNode = new Node(temp->val);
            copyNode->next = nextElement;
            temp->next = copyNode;
            temp = nextElement;
        }
    }
    void ConnectRandomPointers(Node* head)
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            Node* copyNode = temp->next;
            if(temp->random)
            {
                copyNode->random = temp->random->next;
            }
            else
            {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* getDeepCopyListHead(Node* head)
    {
        Node* dmNode = new Node(-1);
        Node* res = dmNode;
        Node* temp = head;
        while(temp != nullptr)
        {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dmNode->next;
    }
    Node* copyRandomList(Node* head) {
       InsertCopyInBetween(head);
       ConnectRandomPointers(head);
       return getDeepCopyListHead(head);
    }
};
