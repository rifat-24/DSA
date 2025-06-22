#include<bits/stdc++.h>
using namespace std;
//#define int long long
int dx[] = {0, -1, 0, +1, -1, -1, +1, +1};
int dy[] = {+1, 0, -1, 0, +1, -1, -1, +1};

 int r, c;
  bool is_v(int i, int j) {
    if(i < r and i >= 0 and j < c and j >= 0) return true;
    return false;
}
void dfs(int i, int j, vector<vector<char>> &v, vector<vector<int>> &vis)  {

    vis[i][j] = true;
    for(int k = 0; k < 4; ++k) {
       int X = i + dx[k];
       int Y = j + dy[k];
       if(is_v(X, Y) and v[X][Y] == '.' and !vis[X][Y]) {
        dfs(X, Y, v, vis);
       }
    }
}
void solve() {

    cin >> r >> c;
   vector<vector<char>>v(r, vector<char>(c, 0));
   for(int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
        cin >> v[i][j];
    }
   }
   vector<vector<int>> vis(r, vector<int> (c, 0));
   int cnt = 0;
   for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; ++j) {
        if(!vis[i][j] and v[i][j] == '.') {
         dfs(i,j, v, vis);
         cnt++;
        }
    }
   }
   cout << cnt << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}
