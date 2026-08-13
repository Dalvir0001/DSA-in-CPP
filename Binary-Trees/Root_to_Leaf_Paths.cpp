// Problem: Root to Leaf Paths
// Approach: DFS + Backtracking
// Time Complexity: O(n)
// Space Complexity: O(h) excluding the answer

// Code :-

/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void solve(Node* root , vector<vector<int>>& ans ,vector<int>& temp)
    {
        if(root==nullptr) return;
        temp.push_back(root->data);
        if(root->left == nullptr && root->right == nullptr) 
        ans.push_back(temp);
        solve(root->left , ans , temp);
        solve(root->right , ans , temp);
        
        return temp.pop_back();
    }
    vector<vector<int>> paths(Node* root) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root,ans,temp);
        return ans;
    }
};