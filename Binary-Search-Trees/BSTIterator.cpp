/*
Problem: Binary Search Tree Iterator

Implement an iterator over a Binary Search Tree (BST).
The iterator should return the next smallest element in the BST
in ascending order.

Approach:
Use a stack to simulate inorder traversal.

Initially, push all the left nodes from the root into the stack.
For each next() call:
1. Take the top node from the stack.
2. If it has a right subtree, push all the left nodes of that
   subtree into the stack.
3. Return the node's value.

This produces the BST elements in sorted order without storing
the entire inorder traversal.

Time Complexity:
- next(): O(1) amortized
- hasNext(): O(1)

Space Complexity: O(h)
where h is the height of the BST.
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
public:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* root = st.top();
        st.pop();

        if (root->right != nullptr) {
            pushLeft(root->right);
        }

        return root->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */