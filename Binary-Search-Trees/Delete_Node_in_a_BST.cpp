/*
    Approach:
    - Search for the node using BST properties.
    - If the node is a leaf, delete it.
    - If it has only one child, replace it with that child.
    - If it has two children, find the inorder successor
      (smallest value in the right subtree).
    - Replace the node's value with the successor's value
      and delete the successor.

    Time Complexity: O(h)
    Space Complexity: O(h)
    where h is the height of the BST.
*/

// Code :-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};