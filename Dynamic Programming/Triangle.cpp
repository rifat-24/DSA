class Solution {
public:
    int f(int i, int j, int siz, vector<vector<int>> &v,  vector<vector<int>> &dp) {
        if(i > siz ) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = INT_MAX;
            int kk = INT_MAX;
           int k = f(i + 1, j, siz, v, dp) + v[i][j];
           if(i + 1 <= siz and  j + 1 < v[i + 1].size()) {
             kk = f(i + 1, j + 1, siz, v, dp) + v[i][j];
           } 
           mn = min(k,kk);

           return dp[i][j] = mn;
        }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size() + 1, vector<int> (triangle.size() + 1, -1));
        return f(0, 0, triangle.size() - 1, triangle, dp);
    }
};
