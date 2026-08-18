/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal

Approach:
- The first element of preorder is always the root.
- Find the root's position in inorder using a hash map.
- Elements before the root belong to the left subtree.
- Elements after the root belong to the right subtree.
- Recursively build both subtrees.

Time Complexity: O(N)
Space Complexity: O(N)
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
    TreeNode* BuildTree(vector<int>& preorder, int preStart , int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int , int>& mpp)
    {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = BuildTree(preorder , preStart + 1, preStart + numsLeft, inorder, inStart, inRoot-1, mpp);
        root->right = BuildTree(preorder , preStart + numsLeft + 1, preEnd, inorder, inRoot+1, inEnd, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> mpp;
        for(int i=0 ; i<inorder.size() ; i++)
        {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = BuildTree(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1 , mpp);
        return root;
    }
};