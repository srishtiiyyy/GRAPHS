#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(int row, int col, vector<vector<int>>& ans, 
             vector<vector<int>>& image, int newColor, int iniColor) {
        
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (isvalid(nrow, ncol, n, m) && 
                image[nrow][ncol] == iniColor && 
                ans[nrow][ncol] != newColor) {
                
                dfs(nrow, ncol, ans, image, newColor, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        if (iniColor != color)  // Optimization: avoid infinite recursion
            dfs(sr, sc, ans, image, color, iniColor);
        return ans;
    }
};

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    cout << "Resultant Image:\n";
    for (auto& row : result) {
        for (auto& cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}
