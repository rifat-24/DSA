
int f(int i, int n, vector<int> &v) {
     if(n == 0) return 0;
	 if(i >= n + 1) return INT_MIN;
	 int take = INT_MIN;
	 if(n - i <= 0)
	   take = f(i, n - i, v) + v[i];

	int not_take = f(i + 1, n, v);

	return max(take, not_take);
}

int cutRod(vector<int> &price, int n)
{
	vector<int> v(n + 1, 0);
	for(int i = 1; i <= n; ++i) v[i] = price[i - 1];
	return f(1, n, v);
	// Write your code here.
}
