// Approach:
// Start from the root and compare val with the current node.
// If val is greater, move to the right subtree.
// Otherwise, move to the left subtree.
// When an empty position is found, insert the new node.
//
// Time Complexity: O(h)
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* temp = root;
        while(temp)
        {
            if(val > temp->val)
            {
                if(temp->right) temp = temp->right;
                else{
                    temp->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(temp->left) temp = temp->left;
                else{
                    temp->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};