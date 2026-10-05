// Course Schedule using Kahn's Algorithm (BFS Topological Sort)
// A valid course schedule exists only if all courses can be processed.
// If the number of processed courses equals numCourses, there is no cycle.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// Code:-

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites)
        {
            int u = edge[0];
            int v = edge[1];
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
        return ans.size() == numCourses;
    }
};