#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
int n;
bool is_valid(int i, int j) {
    if(i < n  and j < n) return true;
    else
    return false;
}

int f(int i, int j, vector<vector<char>> &v, vector<vector<int>> &dp) {
    if(i == n - 1 and j == n - 1) return 1;
    if(dp[i][j] != -1) return (dp[i][j] % mod);
    int a = 0, b = 0;
    if(is_valid(i + 1, j) and v[i + 1][j] != '*') {
         a = f(i + 1, j, v, dp);
    }
    if(is_valid(i, j + 1) and v[i][j + 1] != '*') {
        b = f(i , j + 1, v, dp);
    }

    return dp[i][j] = ((a % mod + b % mod) % mod);
}

void solve() {

    cin >> n;
   vector<vector<char>> v(n, vector<char> (n, 0));
   for(int  i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
        cin >> v[i][j];
    }
   }
   if(v[n - 1][n - 1] == '*' or v[0][0] == '*') {
    cout << 0 << endl;
    return;
   }

   vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
   cout << f(0, 0, v, dp) << endl;



}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
   // cin >> t;
    while(t--) solve();

    return 0;
}
