class Solution {
public:
  bool is_valid(int i, int j, int r, int c) {
    if(i < r and i >=0 and j < c and j >= 0) return true;
    return false;
  }
    void dfs(int i, int j, int r, int c, int orgi, int col, vector<vector<int>>&v, vector<vector<int>>&vis) {
        vis[i][j] = true;
         v[i][j] = col;
        if(is_valid(i + 0, j + 1, r, c) and v[i + 0][j + 1] == orgi and !vis[i + 0][j + 1]) {
            dfs(i + 0, j + 1, r, c, orgi, col, v, vis);
        }
        if(is_valid(i - 1, j + 0, r, c) and v[i - 1][j + 0] == orgi and !vis[i - 1][j + 0]) {
            dfs(i - 1, j + 0, r, c, orgi, col, v, vis);
        }
        if(is_valid(i + 0, j - 1, r, c) and v[i + 0][j - 1] == orgi and !vis[i + 0][j - 1]) {
            dfs(i + 0, j - 1, r, c, orgi, col, v, vis);
        }
        if(is_valid(i + 1, j + 0, r, c) and v[i + 1][j + 0] == orgi and !vis[i + 1][j + 0]) {
            dfs(i + 1, j + 0, r, c, orgi, col, v, vis);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vis(image.size(), vector<int> (image[0].size(), 0));
         dfs(sr, sc,image.size(), image[0].size(), image[sr][sc], color, image, vis);
        return image;
    }
};
