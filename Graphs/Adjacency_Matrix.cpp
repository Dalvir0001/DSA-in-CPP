#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    // n = number of nodes
    // m = number of edges
    cin >> n >> m;

    // Create an (n+1) x (n+1) adjacency matrix
    // We use n+1 so that we can directly use node numbers from 1 to n.
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    // Input the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Since the graph is undirected,
        // if u is connected to v, then v is also connected to u.
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}