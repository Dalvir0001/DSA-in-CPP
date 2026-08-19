// Serialize and Deserialize Binary Tree
// Approach: Level Order Traversal (BFS) using Queue
// Time Complexity: O(n)
// Space Complexity: O(n)

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
class Codec {
public:
    string serialize(TreeNode* root) {
    if (root == nullptr) return "n";

    queue<TreeNode*> q;
    q.push(root);

    string ans = "";

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            ans += "n,";
            continue;
        }

        ans += to_string(node->val) + ",";

        q.push(node->left);
        q.push(node->right);
    }

    ans.pop_back();  // remove last comma
    return ans;
}
    TreeNode* deserialize(string data) {
    if (data == "n") return nullptr;

    stringstream ss(data);
    string value;

    getline(ss, value, ',');
    TreeNode* root = new TreeNode(stoi(value));

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        getline(ss, value, ',');
        if (value != "n") {
            node->left = new TreeNode(stoi(value));
            q.push(node->left);
        }

        getline(ss, value, ',');
        if (value != "n") {
            node->right = new TreeNode(stoi(value));
            q.push(node->right);
        }
    }

    return root;
}

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));