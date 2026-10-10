/*
Problem: Shortest Path in a Directed Acyclic Graph (DAG)
Approach: Topological Sort + Distance Relaxation
Time Complexity: O(V + E)
Space Complexity: O(V + E)

Algorithm:
1. Build the adjacency list with edge weights.
2. Perform DFS-based topological sorting.
3. Initialize all distances to INT_MAX and dist[0] = 0.
4. Process vertices in topological order and relax edges.
5. Replace unreachable distances with -1.
*/

// Code :-


class Solution {
  public:
    void dfs(int i, vector<vector<pair<int,int>>>& adj,
             stack<int>& st, vector<int>& vis)
    {
        vis[i] = 1;

        for(auto it : adj[i])
        {
            int v = it.first;

            if(!vis[v])
            {
                dfs(v, adj, st, vis);
            }
        }

        st.push(i);
    }

    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        stack<int> st;
        vector<int> vis(V, 0);

        // Topological sort
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, st, vis);
            }
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        // Relax edges in topological order
        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            if(dist[node] != INT_MAX)
            {
                for(auto it : adj[node])
                {
                    int v = it.first;
                    int w = it.second;

                    if(dist[node] + w < dist[v])
                    {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }

        // Convert unreachable vertices to -1
        for(int i = 0; i < V; i++)
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
