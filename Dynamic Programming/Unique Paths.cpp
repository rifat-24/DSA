class Solution {
public:
    int f(int r, int c, int m, int n, vector<vector<int>> &dp) {
        if(r > m or c > n) return 0;
        if(r == m and c == n) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        f(r + 1, c, m, n, dp);
        f(r, c + 1, m, n, dp);

        return dp[r][c] = f(r + 1, c, m, n, dp) + f(r ,c + 1 ,m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(1, 1, m, n, dp);
    }
};
