class Solution {
public:
     int f(int i, int j, int r, int c, vector<vector<int>> &v, vector<vector<int>> &dp) {
        if(i > r or j > c) return 0;
        if(v[i][j] == 1) return 0;
        if(i == r and j ==  c) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i + 1, j, r, c,v, dp) + f(i, j + 1, r, c, v, dp);


     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size()+1,-1) );
        return f(0, 0, obstacleGrid.size() -1, obstacleGrid[0].size() -1, obstacleGrid, dp);
    }
};
