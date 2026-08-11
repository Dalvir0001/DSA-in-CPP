/*
    Problem: Boundary Traversal of Binary Tree

    Approach:
    1. Add the root node.
    2. Traverse and add the left boundary excluding leaf nodes.
    3. Add all leaf nodes using DFS.
    4. Traverse the right boundary excluding leaf nodes and add it
       in reverse order.

    Time Complexity: O(N)
    Space Complexity: O(H)
*/

// Code :-

class Solution {
public:
    void solve(Node *root, vector<int> &ans)
    {
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->data);
            return;
        }

        solve(root->left, ans);
        solve(root->right, ans);
    }

    vector<int> boundaryTraversal(Node *root) 
    {
        vector<int> ans;

        if(root == nullptr)
            return ans;

        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->data);
            return ans;
        }

        ans.push_back(root->data);

        Node *temp = root->left;

        while(temp != nullptr)
        {
            if(!(temp->left == nullptr && temp->right == nullptr))
                ans.push_back(temp->data);

            if(temp->left != nullptr)
                temp = temp->left;
            else
                temp = temp->right;
        }
        solve(root, ans);

        vector<int> ref;

        temp = root->right;

        while(temp != nullptr)
        {
            if(!(temp->left == nullptr && temp->right == nullptr))
                ref.push_back(temp->data);

            if(temp->right != nullptr)
                temp = temp->right;
            else
                temp = temp->left;
        }

        for(int i = ref.size() - 1; i >= 0; i--)
        {
            ans.push_back(ref[i]);
        }

        return ans;
    }
};