// Approach: BFS using Reverse Graph and Kahn's Algorithm
// Start with terminal nodes (outdegree = 0) and process their predecessors.
// A node becomes safe when all of its outgoing edges lead to safe nodes.
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Code :-

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adjRev(n);
        vector<int> res;
        vector<int> inDegree(n, 0);

        for(int i = 0; i < n; i++)
        {
            for(int it : graph[i])
            {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(auto it : adjRev[node])
            {
                inDegree[it]--;

                if(inDegree[it] == 0)
                    q.push(it);
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};