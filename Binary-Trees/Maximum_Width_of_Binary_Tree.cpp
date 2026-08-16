// Approach:
// Use level order traversal with index values similar to a complete binary tree.
// Normalize the index at every level to avoid overflow.
// Width = rightmost index - leftmost index + 1.
//
// Time Complexity: O(N)
// Space Complexity: O(N)

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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;

        if (root == nullptr) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            long long mini = q.front().second;
            long long left, right;

            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;
                long long index = p.second - mini;

                if (i == 0)
                    left = index;

                if (i == size - 1)
                    right = index;

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }

            ans = max(ans, right - left + 1);
        }

        return (int)ans;
    }
};