class Solution {
  public:
    bool f(int i, int tar, vector<int> &v, vector<vector<int>> &dp) {
        if(tar == 0) return true;
        if(i == 0) return (v[i] == tar);
        if(dp[i][tar] != -1) return dp[i][tar];
        
        int take = false;
        if(v[i] <= tar) take = f(i - 1, tar - v[i], v, dp);
        
        int not_take = f(i - 1, tar, v, dp);
        
        return dp[i][tar] = (take || not_take);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size() + 1, vector<int> (sum + 1, -1));
        return f(arr.size() - 1, sum, arr, dp);
    }
};
