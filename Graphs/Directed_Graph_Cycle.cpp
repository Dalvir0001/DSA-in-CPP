// Problem: Detect Cycle in a Directed Graph
//
// Approach:
// Use DFS with two arrays:
// 1. vis[]  -> keeps track of visited nodes.
// 2. path[] -> keeps track of nodes in the current DFS recursion path.
//
// If we encounter a node that is already present in the current
// recursion path, a cycle exists.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V)

// Code :-

class Solution {
public:
    bool dfs(vector<int>& vis, vector<vector<int>>& adj,
             vector<int>& path, int node)
    {
        vis[node] = 1;
        path[node] = 1;

        for(auto it : adj[node])
        {
            if(vis[it] == 0)
            {
                if(dfs(vis, adj, path, it))
                    return true;
            }
            else if(path[it] == 1)
            {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(vis, adj, path, i))
                    return true;
            }
        }

        return false;
    }
};