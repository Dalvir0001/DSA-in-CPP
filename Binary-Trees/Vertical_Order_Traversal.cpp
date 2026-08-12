// Problem: Vertical Traversal of Binary Tree
//
// Approach:
// Store each node according to its vertical column (x) and level (y)
// using map<int, map<int, multiset<int>>>.
//
// x-coordinate represents the vertical column.
// y-coordinate represents the depth/level of the node.
// multiset keeps nodes at the same position sorted by value.
//
// We use BFS to traverse the tree level by level.
//
// Time Complexity: O(N log N)
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int,int>>> todo;
        todo.push({root , {0,0}});
        while(!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left)
            todo.push({node->left , {x-1 , y+1}});
            if(node->right)
            todo.push({node->right , {x+1 , y+1}});
        }
        vector<vector<int>> ans;
        for(auto p:nodes)
        {
            vector<int> col;
            for(auto q:p.second)
            {
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};