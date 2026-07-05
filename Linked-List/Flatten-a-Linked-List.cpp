/*
## Problem
Given a linked list where every node has two pointers:
- `next` points to the next linked list.
- `bottom` points to a sorted linked list.

Flatten the entire structure into a single sorted linked list using only the `bottom` pointer.

## Approach
The solution uses recursion and merge.

1. Recursively flatten the linked list starting from the rightmost list.
2. Merge the current list with the already flattened right list.
3. The merge operation is similar to merging two sorted linked lists and uses the `bottom` pointer to build the final list.
4. Set the `next` pointer of merged nodes to `NULL` to maintain the required structure.

## Algorithm
1. If the list is empty or contains only one list, return it.
2. Flatten the remaining lists recursively.
3. Merge the current list with the flattened list.
4. Return the merged list.

## Time Complexity
- **O(N × M)**
  - `N` = Number of linked lists.
  - `M` = Average number of nodes in each bottom list.
*/

// Code :-

class Solution {
public:
    Node* merge(Node* a, Node* b)
    {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while(a != nullptr && b != nullptr)
        {
            if(a->data <= b->data)
            {
                temp->bottom = a;
                temp = a;
                a = a->bottom;
            }
            else
            {
                temp->bottom = b;
                temp = b;
                b = b->bottom;
            }

            temp->next = nullptr;
        }

        if(a)
            temp->bottom = a;
        else
            temp->bottom = b;

        return dummy->bottom;
    }

    Node* flatten(Node* root)
    {
        if(root == nullptr || root->next == nullptr)
            return root;
        root->next = flatten(root->next);
        root = merge(root, root->next);

        return root;
    }
};

## Space Complexity
- **O(N)**
  - Due to the recursion stack.
