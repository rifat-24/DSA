#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int i, int j, string &fs, string &ss, vector<vector<int>> &dp) { 
    if(i < 0 or j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(fs[i] == ss[j]) {
      return dp[i][j] = f(i - 1, j - 1, fs, ss, dp) + 1;
    }
    return dp[i][j] = max(f(i, j - 1, fs, ss, dp) , f(i - 1, j, fs, ss, dp));
}

void print(int i, int j, string &fs, string &ss, string &ans, vector<vector<int>> &dp) {
    if(i < 0 or j < 0) return;
    if(fs[i] == ss[j]) {
       // cout << fs[i];
       ans += fs[i];
        print(i - 1, j - 1, fs, ss, ans, dp);
        return;
    }

    int x = f(i, j - 1, fs, ss, dp);
    int y = f(i - 1, j, fs, ss, dp);
    if(x >= y) {
        print(i, j - 1, fs, ss, ans, dp);
    }
    else print(i - 1, j, fs, ss, ans,dp);
}

void solve() {

   string fs, ss; cin >> fs >> ss;
   string ans;
   vector<vector<int>>dp(fs.size() + 1, vector<int> (ss.size() + 1, -1));
   int k = f(fs.size()-1, ss.size() - 1, fs, ss, dp);
   print(fs.size()-1, ss.size() - 1,fs, ss, ans, dp);
   reverse(ans.begin(), ans.end());
   cout << ans << endl;




}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
   // cin >> t;
    while(t--) solve();

    return 0;
}
