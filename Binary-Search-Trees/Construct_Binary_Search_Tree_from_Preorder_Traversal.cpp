/*
Problem: Construct Binary Search Tree from Preorder Traversal

Approach:
- Use recursion with an upper bound to construct the BST.
- The current preorder element becomes the root.
- Recursively construct the left subtree with the root value as the bound.
- Recursively construct the right subtree using the previous bound.

Time Complexity: O(n)
Space Complexity: O(h)
where n is the number of nodes and h is the height of the BST.
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
    TreeNode* solve(vector<int>& pre, int &i, int bound)
    {
        if(i == pre.size() || pre[i]>bound) return nullptr;
        
        TreeNode* root = new TreeNode(pre[i++]);

        root->left = solve(pre, i, root->val);
        root->right = solve(pre, i, bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder, i, INT_MAX);
    }
};