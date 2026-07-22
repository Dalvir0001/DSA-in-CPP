/*
Problem: M-Coloring Problem

Approach:

Convert the given edge list into an adjacency matrix.
Use backtracking to assign colors to vertices.
Before assigning a color, verify that none of the adjacent vertices already has the same color.
If all vertices are successfully colored, return true; otherwise, backtrack.

Complexity:

Time: O(m^V × V)
Space: O(V + V²) (V² for the adjacency matrix and V for recursion and color array)
*/

// Code :-

class Solution {
  public:
    bool isSafe(int node , vector<int> &colors ,vector<vector<int>> &adj , int v, int col)
    {
        for(int k =0 ; k<v ; k++){
        if(k!=node && adj[k][node] == 1 && colors[k] == col)
        {
            return false;
        }}
        return true;
    }
    bool solve(int node , vector<int> &colors , int m ,int v ,vector<vector<int>> &adj)
    {
        if(node == v)
        {
            return true;
        }
        
        for(int i = 1 ; i <= m ; i++)
        {
            if(isSafe(node , colors , adj , v , i))
            {
                colors[node] = i;
                if(solve(node+1 , colors , m , v , adj))
                return true;
                colors[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
         vector<vector<int>> adj(v, vector<int>(v, 0));

    for (auto &e : edges) {
        int u = e[0];
        int w = e[1];
        adj[u][w] = 1;
        adj[w][u] = 1;
    }

        vector<int> colors(v,0);
        if(solve(0 , colors , m , v , adj)) return true;
        return false;
    }
};