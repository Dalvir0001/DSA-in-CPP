// Binary Tree Level Order Traversal
// Approach: Breadth-First Search (BFS) using Queue
// Traversal: Level by Level, Left to Right
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        vector<int> temp;
        qu.push(root);

        while (!qu.empty()) {
            int size = qu.size();
            temp.clear();

            while (size > 0) {
                TreeNode* node = qu.front();
                qu.pop();

                temp.push_back(node->val);

                if (node->left)
                    qu.push(node->left);

                if (node->right)
                    qu.push(node->right);

                size--;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};