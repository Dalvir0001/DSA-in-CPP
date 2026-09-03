#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    // n = number of nodes
    // m = number of edges
    cin >> n >> m;

    // Create an adjacency list for n nodes.
    // We use n+1 so that we can directly use node numbers from 1 to n.
    vector<vector<int>> adj(n + 1);

    // Input the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Since the graph is undirected,
        // add v to the list of u
        // and u to the list of v.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print the adjacency list
    cout << "Adjacency List:\n";

    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";

        // Print all nodes connected to node i
        for (int neighbour : adj[i]) {
            cout << neighbour << " ";
        }

        cout << endl;
    }

    return 0;
}