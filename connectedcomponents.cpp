#include <bits/stdc++.h>
using namespace std;

// DFS helper function to traverse the component
void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;

    for (auto &neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Function to count connected components in the graph
int countConnectedComponents(int V, vector<vector<int>> &edges) {
    // Build adjacency list
    vector<vector<int>> adj(V);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // because the graph is undirected
    }

    vector<int> visited(V, 0);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            // Each unvisited node starts a new component
            dfs(i, adj, visited);
            components++;
        }
    }

    return components;
}

// Main function
int main() {
    // Example 1
    int V1 = 4;
    vector<vector<int>> edges1 = {{0,1},{1,2}};
    cout << "Number of connected components: " 
         << countConnectedComponents(V1, edges1) << endl;

    // Example 2
    int V2 = 7;
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{4,5}};
    cout << "Number of connected components: " 
         << countConnectedComponents(V2, edges2) << endl;

    // Example 3
    int V3 = 5;
    vector<vector<int>> edges3 = {{0,1},{1,2},{3,4}};
    cout << "Number of connected components: " 
         << countConnectedComponents(V3, edges3) << endl;

    return 0;
}
