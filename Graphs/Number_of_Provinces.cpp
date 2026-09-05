/*
Problem: Number of Provinces

Approach:
1. Convert the given adjacency matrix into an adjacency list.
2. Use DFS to traverse all connected nodes.
3. Every time we find an unvisited node, it represents a new province.
4. Count the number of DFS calls to get the total number of provinces.

Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

// Code :-

class Solution {
public:

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj);
                ans++;
            }
        }

        return ans;
    }
};