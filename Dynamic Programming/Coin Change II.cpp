class Solution {
public:
    int f(int i, int amount, vector<int> &a, vector<vector<int>> &dp) {
        if(amount == 0) return 1;
        if(i < 0) return 0;
        
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 0;
        if(a[i] <= amount)
         take = f(i, amount - a[i], a, dp);
        int not_take = f(i - 1, amount, a, dp);

        return dp[i][amount] = (take + not_take);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
       return f(coins.size() - 1, amount, coins, dp);
    }
};
