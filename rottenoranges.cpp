#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    bool isvalid(int i, int j, int n, int m) {
        if (i < 0 || i >= n) return false;
        if (j < 0 || j >= m) return false;
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;

        // Step 1: Push all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        int cnt = 0;

        // Step 2: BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (isvalid(nrow, ncol, n, m) && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    cnt++;
                }
            }
        }

        // Step 3: Check if all fresh oranges rotted
        if (cnt != fresh) return -1;
        return time;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution sol;
    int result = sol.orangesRotting(grid);

    cout << "Minimum time required to rot all oranges: " << result << " minutes" << endl;
    return 0;
}
