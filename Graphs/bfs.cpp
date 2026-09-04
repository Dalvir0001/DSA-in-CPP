// Breadth First Search (BFS) Traversal
// BFS traverses a graph level by level using a queue.
// A visited array is used to avoid visiting the same node multiple times.
// The traversal starts from node 0.

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        queue<int> q;
        vector<int> vis(adj.size(), 0);

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int num = q.front();
            q.pop();

            for (auto it : adj[num]) {
                if (vis[it] != 1) {
                    q.push(it);
                    vis[it] = 1;
                }
            }

            ans.push_back(num);
        }

        return ans;
    }
};