class Solution {
public:
    int f(int i, int j, int sz, vector<vector<int>> &v, vector<vector<int>> &dp) {
        if(i > sz) return 0;
        if(dp[i][j] != -200) return dp[i][j];
        int a = f(i + 1, j, sz, v, dp) + v[i][j];
        int b = INT_MAX;                                                            
        if(j - 1 >= 0) {
            b = f(i + 1, j - 1, sz, v, dp) + v[i][j];
        }
        int c = INT_MAX;
        if(j + 1 <= sz) {
            c = f(i + 1, j + 1, sz, v, dp) + v[i][j];
        }

        return dp[i][j] = min({a, b, c});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int> (matrix.size() + 1, -200));
        int mn = INT_MAX;
        for(int i = 0; i < matrix[0].size(); ++i) {
            mn = min(f(0, i, matrix.size() - 1, matrix, dp), mn);
        }
        return mn;
    }
};
