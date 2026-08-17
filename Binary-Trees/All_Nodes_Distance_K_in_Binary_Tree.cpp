// Approach:
// 1. Store the parent of every node using BFS.
// 2. Treat the binary tree like an undirected graph.
// 3. Start BFS from the target node.
// 4. From each node, move to its left child, right child, and parent.
// 5. Use a visited map to avoid visiting the same node again.
// 6. When the distance reaches k, store all nodes present in the queue.

// Code :-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& mark_parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
            {
                mark_parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                mark_parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> mark_parent;
        markParent(root , mark_parent);
        queue<TreeNode*> q;
        unordered_map<TreeNode* , bool> vis;
        q.push(target);
        int curr_level = 0;
        vis[target] = true;
        while(!q.empty())
        {
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i=0 ; i<size ; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(mark_parent[curr] && !vis[mark_parent[curr]])
                {
                    q.push(mark_parent[curr]);
                    vis[mark_parent[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};