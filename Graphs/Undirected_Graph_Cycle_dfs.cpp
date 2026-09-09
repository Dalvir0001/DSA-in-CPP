/*
    Problem: Detect Cycle in an Undirected Graph

    Approach:
    - Build an adjacency list from the given edges.
    - Use DFS to traverse the graph.
    - Keep track of the parent of each node.
    - If we encounter a visited node that is not the parent,
      then a cycle exists.
    - Run DFS from every unvisited vertex to handle disconnected graphs.

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)
*/

// Code :-

class Solution {
public:

    bool dfs(int src,int parent, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[src] = 1;
        for(auto it : adj[src])
        {
            if(vis[it] == 0)
            {
                if(dfs(it,src, adj, vis) == true) return true;
            }
            else if(it  != parent)
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(V);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i,-1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};