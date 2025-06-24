#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int n, int pri_ind, vector<vector<int>>&v, vector<vector<int>> &dp) {
    if(n == -1) return 0;
    if(dp[n][pri_ind] != -1) return dp[n][pri_ind];
    int mx = 0;
    for(int i = 0; i < 3; ++i){
        if(i != pri_ind) {
           mx = max(mx, f(n - 1, i, v, dp) + v[n][i]);
        }
    }
    return dp[n][pri_ind] = mx;
}

void solve() {

   int n; cin >> n;
   vector<vector<int>> v(n, vector<int> (3, 0));
   vector<vector<int>>dp(n + 1, vector<int> (4 , -1));
   for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 3; ++j) {
        cin >> v[i][j];
    }
   }
   cout << f(n - 1, 3, v, dp) << endl;


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
   // cin >> t;
    while(t--) solve();

    return 0;
}
