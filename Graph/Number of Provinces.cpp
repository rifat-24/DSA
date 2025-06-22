class Solution {
public:
     void dfs(int u, vector<vector<int>> &g, vector<int> &vis) {
        vis[u] = true;
        for(auto v: g[u]) {
        if(!vis[v]) {
            dfs(v, g, vis);
        }
        }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> g(isConnected.size());
        for(int i = 0; i < isConnected.size(); ++i) {
            for(int j = 0; j < isConnected.size(); ++j) {
                if(isConnected[i][j] == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            } 
        }
        vector<int> vis(isConnected.size(), 0);
        int cnt = 0;
        for(int i = 0; i < isConnected.size(); ++i) {
            if(!vis[i]) {
                dfs(i, g, vis);
                cnt++;
            }
        }
        return cnt;

    }
};
