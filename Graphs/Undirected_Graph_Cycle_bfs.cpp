// Problem: Undirected Graph Cycle
// Approach: BFS with Parent Tracking
//
// Explanation:
// First convert the given edge list into an adjacency list.
// Then perform BFS from every unvisited node because the graph
// can contain multiple components.
//
// During BFS, store both the current node and its parent.
// If an adjacent node is unvisited, mark it visited and add it
// to the queue with the current node as its parent.
// If an adjacent node is already visited and it is not the parent,
// then a cycle exists.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution { 
public: 
 
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) 
    { 
        vis[src] = 1; 
 
        queue<pair<int, int>> q; 
        q.push({src, -1}); 
 
        while (!q.empty()) 
        { 
            int node = q.front().first; 
            int parent = q.front().second; 
 
            q.pop(); 
 
            for (auto adjacentNode : adj[node]) 
            { 
                if (!vis[adjacentNode]) 
                { 
                    vis[adjacentNode] = 1; 
                    q.push({adjacentNode, node}); 
                } 
                else if (parent != adjacentNode) 
                { 
                    return true; 
                } 
            } 
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
                if (detect(i, adj, vis)) 
                    return true; 
            } 
        } 
 
        return false; 
    } 
};