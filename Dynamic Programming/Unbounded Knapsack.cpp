
int f(int i, int wight, vector<int> &p, vector<int> &w, vector<vector<int>> &dp) {
    if(i == -1) return 0;
    if(dp[i][wight] != -1) return dp[i][wight];
    int take = 0;
    if(w[i] <= wight) take = f(i, wight - w[i], p, w, dp) + p[i];
    int not_take = f(i - 1, wight, p, w,dp);

    return dp[i][wight] = max(take, not_take);
}

int unboundedKnapsack(int n, int wight, vector<int> &p, vector<int> &w){
    // Write Your Code Her
    vector<vector<int>> dp(n + 1, vector<int> (wight + 1, -1));
    return f(n - 1, wight, p, w, dp);

}
