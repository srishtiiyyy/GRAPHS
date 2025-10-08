/*
------------------------------------------------------------
🧩 Problem: Rotten Oranges (LeetCode 994)
------------------------------------------------------------
You are given an m x n grid where each cell can have one of three values:

0 → Empty cell  
1 → Fresh orange  
2 → Rotten orange  

Every minute, any fresh orange that is 4-directionally adjacent to a rotten one becomes rotten.

Return the **minimum number of minutes** that must elapse until no cell has a fresh orange.  
If it is **impossible** to rot all oranges, return **-1**.

------------------------------------------------------------
Example:
Input:
grid = [
  [2,1,1],
  [1,1,0],
  [0,1,1]
]

Output: 4

Explanation:
After 4 minutes, all oranges become rotten.

------------------------------------------------------------
Constraints:
1 ≤ m, n ≤ 100
------------------------------------------------------------
Approach:
✅ Use **Breadth First Search (BFS)** since all rotten oranges rot their neighbors simultaneously each minute.
✅ Each level in BFS = 1 minute.
✅ Keep track of:
   - Fresh oranges count
   - Time elapsed
✅ Push all rotten oranges into queue initially with time=0.
✅ Perform BFS traversal, infecting adjacent fresh oranges.
✅ At the end:
   - If not all fresh oranges are rotted → return -1.
   - Else return time elapsed.

------------------------------------------------------------
Time Complexity:  O(N*M)
Space Complexity: O(N*M)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Directions for 4-adjacent cells (up, right, down, left)
vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

// Utility function to check if a cell is valid
bool isValid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// Function to find minimum time required to rot all oranges
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q; // {{row, col}, time}
    int fresh = 0;

    // Step 1️⃣: Push all initially rotten oranges and count fresh ones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int time = 0;  // Total minutes elapsed
    int cnt = 0;   // Count of oranges that turned rotten

    // Step 2️⃣: Perform BFS traversal
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        time = max(time, t); // Track latest minute

        // Traverse all 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1) {
                grid[nrow][ncol] = 2;            // Make orange rotten
                q.push({{nrow, ncol}, t + 1});   // Add to queue with updated time
                cnt++;                            // Increment rotten count
            }
        }
    }

    // Step 3️⃣: If some fresh oranges never rotted → impossible
    if (cnt != fresh) return -1;
    return time;
}

// Driver code
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "\n🍊 Rotten Oranges (BFS Solution)\n";
    cout << "--------------------------------------\n";
    int result = orangesRotting(grid);
    cout << "Minimum time required to rot all oranges: " 
         << result << " minute(s)\n";
    return 0;
}
