#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt = 1;

int f(int i, vector<int>&a, vector<int>&dp) {
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];
    int take = f(i - 2, a, dp) + a[i];
    int not_take = f(i - 1, a, dp) + 0;

    return dp[i] = max(take, not_take);
}

void solve() {

   int n; cin >> n;
   vector<int> a(n), b(n-1);
   for(int i = 0; i < n; ++i) cin >> a[i];
   for(int i = 1; i < n; ++i) b[i - 1] = a[i];
   vector<int> dp(n + 1, -1);

   int m = f(n - 2, b, dp);
   a.pop_back();

   fill(dp.begin(), dp.end(), -1);

   int k = f(n - 2, a, dp);
   cout << "Case " << cnt << ": " << max(m, k) << endl;
   cnt++;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}
