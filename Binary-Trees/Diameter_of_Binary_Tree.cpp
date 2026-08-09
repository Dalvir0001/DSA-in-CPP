// Problem: Diameter of Binary Tree
// Approach: Recursive DFS with Height Calculation
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

// Problem: Diameter of Binary Tree
// Approach: Recursive DFS with Height Calculation
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    int dfsHeight(TreeNode* root, int &diameter)
    {
        if(root == nullptr) return 0;

        int l = dfsHeight(root->left, diameter);
        int r = dfsHeight(root->right, diameter);

        diameter = max(diameter, l + r);

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfsHeight(root, diameter);
        return diameter;
    }
};