// Find Ceil in a BST
// Time Complexity: O(h)
// Space Complexity: O(1)

// Code :-

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
    int findCeil(Node* root, int x) {
        int ans = -1;
        while(root != nullptr)
        {
            if(root->data == x)
            {
                ans = root->data;
                return ans;
            }
            if(root->data > x)
            {
                ans = root->data;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ans;
    }
};
