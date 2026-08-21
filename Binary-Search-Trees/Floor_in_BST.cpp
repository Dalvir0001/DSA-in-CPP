// Find Floor in a BST
// Time Complexity: O(h)
// Space Complexity: O(1)

// Code :-

/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        while(root != nullptr)
        {
            if(root->data == k)
            {
                ans = root->data;
                return ans;
            }
            if(root->data < k)
            {
                ans = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return ans;
    }
};