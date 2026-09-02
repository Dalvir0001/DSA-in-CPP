/*
    Maximum Sum BST in Binary Tree

    Approach:
    Use postorder recursion to determine whether each subtree is a BST.
    For every subtree, store:
    - isBST  -> whether the subtree is a BST
    - sum    -> sum of nodes in the subtree
    - minVal -> minimum value in the subtree
    - maxVal -> maximum value in the subtree

    Time Complexity: O(n)
    Space Complexity: O(h)
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
    int ans = 0;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info solve(TreeNode* root) {
        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int sum = left.sum + root->val + right.sum;

            ans = max(ans, sum);

            return {
                true,
                sum,
                min(left.minVal, root->val),
                max(right.maxVal, root->val)
            };
        }

        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};