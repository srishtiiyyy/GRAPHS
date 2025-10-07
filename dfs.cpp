/*
    💡 Problem: Depth-First Traversal of a Graph
    🔗 Example / Concept: DFS traversal using recursion
    🧠 Level: Medium
    🎯 Topic: Graph Traversal

    📌 Problem Summary:
    Given a graph as an adjacency list, return the DFS traversal starting from node 0.
*/

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------------------
// 🔹 DFS Helper Function
// -----------------------------------------------------------------------------------------
void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &dfsTraversal) {
    visited[node] = 1;
    dfsTraversal.push_back(node);

    for (auto &neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, dfsTraversal);
        }
    }
}

// -----------------------------------------------------------------------------------------
// 🔹 DFS Main Function
// -----------------------------------------------------------------------------------------
vector<int> dfsGraph(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> dfsTraversal;

    dfsHelper(0, adj, visited, dfsTraversal); // start DFS from node 0

    return dfsTraversal;
}

// -----------------------------------------------------------------------------------------
// 🔹 Main Function
// -----------------------------------------------------------------------------------------
int main() {
    // Example graph with 5 nodes
    vector<vector<int>> adj = {
        {1, 2, 3}, // edges from node 0
        {0},       // edges from node 1
        {0, 4},    // edges from node 2
        {0},       // edges from node 3
        {2}        // edges from node 4
    };

    vector<int> dfsTraversal = dfsGraph(adj);

    cout << "DFS Traversal: ";
    for (int node : dfsTraversal) cout << node << " ";
    cout << endl;

    return 0;
}

/***************************************************************** NOTES *****************************************************************
🧠 Key Ideas:
- DFS uses recursion and a visited array to avoid revisiting nodes.
- Traversal starts from node 0.
- Explores as far as possible along each branch before backtracking.

📝 Complexity:
- Time: O(V + E)
- Space: O(V) for recursion stack + O(V) for visited array
*****************************************************************************************************************************************/
