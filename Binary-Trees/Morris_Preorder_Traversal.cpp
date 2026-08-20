// Morris Preorder Traversal
// Approach:
// 1. If the current node has no left child, visit it and move right.
// 2. Otherwise, find the rightmost node in the left subtree (predecessor).
// 3. Create a temporary link from the predecessor to the current node.
// 4. Visit the current node before moving to the left subtree.
// 5. When the temporary link is encountered again, remove it and move right.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != nullptr)
        {
            if(curr->left == nullptr)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right!=nullptr && prev->right!=curr)
                {
                    prev = prev->right;
                }
                if(prev->right == nullptr)
                {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};