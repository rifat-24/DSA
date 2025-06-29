class Solution {
    int f(int i, int amount, vector<int> &a, vector<vector<int>> &dp) {
        if(amount == 0) return 0;
        if(i < 0) return 1e4 + 1; 
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 1e4 + 1;
        if(a[i] <= amount) {
          take = f(i, amount - a[i], a, dp) + 1;
        }
        int not_take = f(i - 1, amount, a, dp) + 0;

        return dp[i][amount] = min(take, not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       // return f(coins.size() - 1, amount, coins);
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
       int k = f(coins.size() - 1, amount, coins, dp);
       if(k > 1e4) return -1;
       return  k;
        
    }
};
