class Solution {
public:
     void f(int i, int n,vector<vector<int>> &ans, vector<int>&v,vector<int> &dum, int target) {     
      if(target == 0) {
        ans.push_back(dum);
        return;
      }
      if(i >= n) return;
      if(target < 0) {
        return;
      }
        dum.push_back(v[i]);
        f(i, n, ans, v, dum, target - v[i]);
        dum.pop_back();

        f(i + 1, n, ans, v, dum, target);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> dum;
        f(0, candidates.size(), ans, candidates,dum, target);
        return ans;
    }
};
