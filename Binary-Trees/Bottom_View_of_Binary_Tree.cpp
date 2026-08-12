/*
Approach:
- Use level order traversal (BFS) with a horizontal distance for each node.
- The root has horizontal distance 0.
- For every left child, decrease the horizontal distance by 1.
- For every right child, increase the horizontal distance by 1.
- Store the latest node value for each horizontal distance in a map.
- Finally, traverse the map from left to right to get the bottom view.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/

// Code :-

/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
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
            mpp[hd] = node->data;
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