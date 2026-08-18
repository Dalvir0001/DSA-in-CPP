/*
Problem: Burning Tree
Approach:
1. Store the parent of every node using BFS.
2. Find the target node during the same traversal.
3. Start BFS from the target node.
4. Burn left child, right child, and parent level by level.
5. Count the time required to burn the entire tree.

Time Complexity: O(N)
Space Complexity: O(N)
*/


// Code :-
/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        if (root == nullptr) return 0;

        unordered_map<Node*, Node*> parent;
        unordered_map<Node*, bool> vis;
        queue<Node*> q;

        Node* targetNode = nullptr;

        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->data == target)
                targetNode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        q.push(targetNode);
        vis[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                    burned = true;
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                    burned = true;
                }

                if (parent[node] && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                    burned = true;
                }
            }

            if (burned)
                time++;
        }

        return time;
    }
};