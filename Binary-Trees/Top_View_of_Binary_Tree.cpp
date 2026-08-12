// Top View of Binary Tree
// Approach: BFS + Horizontal Distance
// Time Complexity: O(N log N)
// Space Complexity: O(N)

// Code :-

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        map<int,int> mpp;
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        while(!q.empty())
        {
            auto a = q.front();
            Node* node = a.first;
            int hd = a.second;
            q.pop();
            if(!mpp.count(hd))
            {
                mpp[hd] = node->data;
            }
            if(node->left)
            q.push({node->left , hd-1});
            if(node->right)
            q.push({node->right , hd+1});
        }
        for(auto p:mpp)
        {
            ans.push_back(p.second);
        }
    return ans;
    }
};