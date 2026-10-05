// Topological Sort using Kahn's Algorithm (BFS)
// Calculate indegree of each node and process nodes with indegree 0.
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Code :-

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> inDegree(V,0);
        vector<vector<int>> adj(V);
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};