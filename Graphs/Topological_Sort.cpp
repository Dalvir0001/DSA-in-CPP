// Topological Sort using DFS
// Build a directed adjacency list from the given edges.
// Perform DFS and push each node into a stack after visiting all its neighbors.
// Pop the stack to get the topological ordering.

// Code :-

class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st)
    {
        vis[node] = 1;
        for(auto it: adj[node])
        {
            if(!vis[it]) dfs(it,vis,adj,st);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> vis(V,0);
        stack<int> st;
        vector<vector<int>> adj(V);
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for(int i=0; i<V ;i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    return ans;
    }
};