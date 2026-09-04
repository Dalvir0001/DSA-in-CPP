// Depth First Search (DFS) Traversal
// DFS explores a graph by going as deep as possible before backtracking.
// Recursion is used to traverse the graph.
// A visited array is used to avoid visiting the same node multiple times.
// The traversal starts from node 0.

class Solution {
  public:
    void solve(int node, vector<vector<int>>& adj, vector<int>& ans, vector<int>& vis)
    {
        vis[node] = 1;
        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (vis[it] != 1)
            {
                solve(it, adj, ans, vis);
            }
        }

        return;
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<int> vis(adj.size(), 0);

        int start = 0;
        solve(start, adj, ans, vis);

        return ans;
    }
};