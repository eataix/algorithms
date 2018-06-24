class Solution {
public:
  /**
   * @param candidates: A list of integers
   * @param target: An integer
   * @return: A list of lists of integers
   */
  vector<vector<int>> combinationSum(vector<int> candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> out;

    dfs(candidates, target, 0, out, res);
    return res;
  }

  void dfs(const vector<int> &candidates, int target, int start,
           vector<int> &out, vector<vector<int>> &res) {
    if (target == 0) {
      res.push_back(out);
    } else if (target < 0) {
      return;
    } else {
      for (int i = start; i < candidates.size(); ++i) {
        out.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i, out, res);
        out.pop_back();
      }
    }
  }
};
