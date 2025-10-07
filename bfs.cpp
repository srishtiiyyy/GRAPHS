/*
    💡 Problem: Breadth-First Traversal of a Graph
    🔗 Example / Concept: BFS traversal using queue
    🧠 Level: Medium
    🎯 Topic: Graph Traversal

    📌 Problem Summary:
    Given a graph as an adjacency list, return the BFS traversal starting from node 0.
*/

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------------------
// 🔹 BFS Function
// -----------------------------------------------------------------------------------------
vector<int> bfsGraph(vector<vector<int>> &adj) {
    int v = adj.size();
    vector<int> visited(v, 0);
    vector<int> bfs;

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto &neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return bfs;
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

    vector<int> bfsTraversal = bfsGraph(adj);

    cout << "BFS Traversal: ";
    for (int node : bfsTraversal) cout << node << " ";
    cout << endl;

    return 0;
}

/***************************************************************** NOTES *****************************************************************
🧠 Key Ideas:
- BFS uses a queue and a visited array to avoid revisiting nodes.
- Traversal starts from node 0.
- Handles connected components starting from 0.

📝 Complexity:
- Time: O(V + E)
- Space: O(V) for visited + O(V) for queue
*****************************************************************************************************************************************/
