// Problem: Binary Tree Zigzag Level Order Traversal
// Approach: BFS / Level Order Traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        bool toggle = true;
        qu.push(root);

        while (!qu.empty()) {
            int size = qu.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = qu.front();
                qu.pop();

                int index = (toggle) ? i : size - i - 1;
                row[index] = node->val;

                if (node->left)
                    qu.push(node->left);

                if (node->right)
                    qu.push(node->right);
            }

            toggle = !toggle;
            ans.push_back(row);
        }

        return ans;
    }
};