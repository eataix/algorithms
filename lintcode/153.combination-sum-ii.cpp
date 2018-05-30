#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  /**
   * @param num: Given the candidate numbers
   * @param target: Given the target number
   * @return: All the combinations that sum to target
   */
  vector<vector<int>> combinationSum2(vector<int> &num, int target) {
    vector<vector<int>> res;
    vector<int> out;
    sort(num.begin(), num.end());
    combinationSum2DFS(num, res, out, 0, target);
    return res;
  }

  void combinationSum2DFS(const vector<int> &num, vector<vector<int>> &res,
                          vector<int> &out, int start, int target) {
    if (target == 0) {
      res.push_back(out);
      return;
    } else if (target < 0) {
      return;
    } else {
      for (int i = start; i < num.size(); ++i) {
        if (i > start && num[i] == num[i - 1]) {
          continue;
        }
        out.push_back(num[i]);
        combinationSum2DFS(num, res, out, i + 1, target - num[i]);
        out.pop_back();
      }
    }
  }
};
