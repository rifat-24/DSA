
int f(int i, int tar, vector<int> &a, vector<vector<int>>&dp, int mod) {
	if(i < 0 and tar == 0) return true;
	if(i < 0 and tar != 0) return false;
	
	if(dp[i][tar] != -1) return dp[i][tar];
	int take = 0;
	if(a[i] <= tar) take = f(i - 1, tar - a[i], a,dp, mod);

	int not_take = f(i - 1, tar, a, dp, mod);

	return dp[i][tar] = (take + not_take) % mod;
}

int findWays(vector<int>& arr, int k)
{
	const int mod = 1e9 + 7;
	vector<vector<int>> dp(arr.size() + 1, vector<int> (k + 1,-1));
	return f(arr.size() -1, k, arr, dp, mod);
}
