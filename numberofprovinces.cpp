#include <bits/stdc++.h>
using namespace std;

// DFS helper function
void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adjLs[node]) {
        if (!vis[it]) {
            dfs(it, adjLs, vis);
        }
    }
}

// Function to find number of connected components (provinces)
int findCircleNum(vector<vector<int>> &isConnected) {
    int V = isConnected.size();
    vector<vector<int>> adjLs(V);

    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, adjLs, vis);
        }
    }

    return count;
}

int main() {
    // Example input 1
    vector<vector<int>> isConnected1 = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << "Number of provinces: " << findCircleNum(isConnected1) << endl;

    // Example input 2
    vector<vector<int>> isConnected2 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout << "Number of provinces: " << findCircleNum(isConnected2) << endl;

    return 0;
}
