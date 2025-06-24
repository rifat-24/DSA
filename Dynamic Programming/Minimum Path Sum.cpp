class Solution {
public:
     int f(int i, int j, int r, int c, vector<vector<int>> &v, int inf, vector<vector<int>> &dp) {
        
        if(i > r or j > c) return inf;
        if(i == r and j == c) return v[i][j];
        if(dp[i][j] != -1) return dp[i][j];
         int down = f(i + 1, j, r, c, v, inf, dp) + v[i][j];
         int right = f(i, j + 1, r, c, v, inf, dp) + v[i][j];

         return dp[i][j] = min(down, right);
     }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int> (grid[0].size() + 1, -1));
        return f(0, 0, grid.size() - 1, grid[0].size() - 1, grid, 1e5, dp);
    }
};
