// Flatten Binary Tree to Linked List
// Approach:
// 1. Traverse the tree using the right pointer.
// 2. If the current node has a left subtree, find the rightmost node of it.
// 3. Connect the current right subtree to the rightmost node.
// 4. Move the left subtree to the right and set the left pointer to nullptr.
// 5. Continue until all nodes are processed.
//
// Time Complexity: O(n^2) in the worst case
// Space Complexity: O(1)

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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* curr = root;
        while(curr != nullptr)
        {
            if(curr->left != nullptr)
            {
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;  
                curr->left = nullptr;  
            }
            curr = curr->right;
        }
    }
};