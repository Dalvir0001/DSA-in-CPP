// Approach:
// 1. Find the height of the leftmost and rightmost paths.
// 2. If both heights are equal, the tree is perfect.
// 3. A perfect binary tree with height h has (2^h - 1) nodes.
// 4. Otherwise, recursively count nodes in the left and right subtrees.
//
// Time Complexity: O(log^2 N)
// Space Complexity: O(log N) due to recursion

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
    int leftHeight(TreeNode* root)
    {
        int height = 0;
        while(root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    int rightHeight(TreeNode* root)
    {
        int height = 0;
        while(root)
        {
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = leftHeight(root);
        int right = rightHeight(root);

        if(left == right) return (1<<left) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};