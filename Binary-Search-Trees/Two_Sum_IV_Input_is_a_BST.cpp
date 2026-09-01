/*
    Problem: Two Sum IV - Input is a BST

    Approach:
    Use two BST Iterators:
    1. Normal inorder traversal gives elements in ascending order.
    2. Reverse inorder traversal gives elements in descending order.
    
    Use both iterators like the two-pointer approach on a sorted array.
    
    If the current sum is:
    - Equal to k  -> return true
    - Less than k  -> move the left iterator forward
    - Greater than k -> move the right iterator backward

    Time Complexity: O(N)
    Space Complexity: O(H)

    Where:
    N = Number of nodes in the BST
    H = Height of the BST
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
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (reverse)
            pushAll(node->left);
        else
            pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false);  
        BSTIterator r(root, true);   

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k)
                return true;

            if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};