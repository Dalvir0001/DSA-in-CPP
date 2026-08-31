/*
Problem: Inorder Successor in BST

Given a Binary Search Tree (BST) and a node k, find the inorder
successor of k. If there is no inorder successor, return -1.

Approach:
Since it is a BST, if root->data <= k->data, the successor must
be in the right subtree.

Otherwise, the current node can be a possible successor. Store it
and move to the left subtree to find a smaller valid successor.

Continue until the tree becomes NULL.

Time Complexity: O(h)
Space Complexity: O(1)
where h is the height of the BST.
*/

/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        Node* result = nullptr;

        while(root != nullptr) {
            if(root->data <= k->data) {
                root = root->right;
            }
            else {
                result = root;
                root = root->left;
            }
        }

        if(result == nullptr)
            return -1;

        return result->data;
    }
};