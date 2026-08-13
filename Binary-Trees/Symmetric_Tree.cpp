// Problem: Symmetric Tree
// Approach: Recursive DFS
// Compare mirror nodes: left->left with right->right
//                 and left->right with right->left
// Time Complexity: O(n)
// Space Complexity: O(h)

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
    bool check(TreeNode* left , TreeNode* right)
    {
        if(left == nullptr || right==nullptr) return left==right;
        if(left->val != right->val) return false;
        return check(left->left , right->right)&&check(left->right , right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==nullptr || check(root->left,root->right);
    }
};