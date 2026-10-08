// Alien Dictionary
// Approach: Build a directed graph using the first different character
// of every pair of adjacent words, then apply Kahn's Algorithm
// (BFS Topological Sort) to find the valid character ordering.

// Code :-

class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();

        vector<vector<int>> adj(26);

        // Build graph
        for(int i = 1; i < n; i++)
        {
            int len = min(words[i-1].size(), words[i].size());

            int j = 0;

            for(; j < len; j++)
            {
                if(words[i-1][j] != words[i][j])
                {
                    int u = words[i-1][j] - 'a';
                    int v = words[i][j] - 'a';

                    adj[u].push_back(v);

                    break;
                }
            }

            // Invalid prefix case
            if(j == len && words[i-1].size() > words[i].size())
                return "";
        }

        // Calculate indegree
        vector<int> inDegree(26, 0);

        for(int u = 0; u < 26; u++)
        {
            for(int v : adj[u])
            {
                inDegree[v]++;
            }
        }

        // Find characters that actually exist
        vector<bool> present(26, false);

        for(string word : words)
        {
            for(char ch : word)
            {
                present[ch - 'a'] = true;
            }
        }

        // Push all zero-indegree characters
        queue<int> q;

        for(int i = 0; i < 26; i++)
        {
            if(present[i] && inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Topological sort
        string ans;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node + 'a');

            for(int it : adj[node])
            {
                inDegree[it]--;

                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // Cycle detection
        int totalCharacters = 0;

        for(int i = 0; i < 26; i++)
        {
            if(present[i])
                totalCharacters++;
        }

        if(ans.size() != totalCharacters)
            return "";

        return ans;
    }
};