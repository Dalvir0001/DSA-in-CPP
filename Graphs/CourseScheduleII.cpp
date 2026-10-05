// Course Schedule II using Kahn's Algorithm (BFS Topological Sort)
// Build the graph according to prerequisite order and calculate indegrees.
// Process all courses with indegree 0 to generate a valid course order.
// If all courses are processed, return the order; otherwise, a cycle exists.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Code:-

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites)
        {
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
        }
        for(int i=0; i<numCourses; i++)
        {
            for(auto it: adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
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
        if(ans.size() == numCourses) return ans;
        return {};
    }
};