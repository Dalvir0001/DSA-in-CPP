/*
    Problem: Recover Binary Search Tree

    Approach:
    In a Binary Search Tree, inorder traversal gives the nodes
    in sorted order.

    If two nodes are swapped, the inorder traversal will contain
    one or two violations where:
    
        prev->val > root->val

    We identify:
    - first  -> first misplaced node
    - second -> second misplaced node

    For the first violation:
        first = prev

    For every violation:
        second = root

    Finally, swap the values of first and second to recover the BST.

    Time Complexity: O(N)
    Space Complexity: O(H)

    Where:
    N = Number of nodes in the tree
    H = Height of the tree
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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void solve(TreeNode* root) {
        if (root == nullptr)
            return;

        solve(root->left);

        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr)
                first = prev;

            second = root;
        }

        prev = root;

        solve(root->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);

        swap(first->val, second->val);
    }
};