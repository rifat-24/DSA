#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt = 1;

int f(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp) {
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int  mn = INT_MAX;
    for(int k = 0; k < 3; ++k) {
        if(k >= 0 and k != j) mn = min(mn, f(i - 1, k, v, dp) + v[i][j]);
    }
    return dp[i][j] = mn;
}

void solve() {

   int n; cin >> n;
   vector<vector<int>> v(n, vector<int> (3, 0));
   for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 3; ++j) {
        cin >> v[i][j];
    }
   }
   vector<vector<int>> dp(n + 1, vector<int> (4, -1));
   int mn = INT_MAX;
   for(int i = 0; i < 3; ++i) {
     mn = min(mn, f(n - 1, i, v, dp));
   }
   cout << "Case " << cnt << ": " <<  mn << endl;
   cnt++;
  // cout << mn << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}
