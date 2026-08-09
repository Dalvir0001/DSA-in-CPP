// Problem: Balanced Binary Tree
// Approach: Recursive DFS with Height Check
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
 *     TreeNode(int x) : val(x), left(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfsHeight(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int l = dfsHeight(root->left);
        if(l == -1) return -1;

        int r = dfsHeight(root->right);
        if(r == -1) return -1;

        if(abs(l - r) > 1) return -1;

        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};