#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param num: Given the candidate numbers
   * @param target: Given the target number
   * @return: All the combinations that sum to target
   */
  vector<vector<int>> combinationSum2(vector<int> num, int target) {
    sort(num.begin(), num.end());
    vector<vector<int>> res;
    vector<int> out;
    dfs(num, target, 0, out, res);
#ifdef DEBUG
    for (auto r : res) {
      for (auto r1 : r) {
        cout << r1 << " ";
      }
      cout << endl;
    }
#endif
    return res;
  }

  void dfs(const vector<int> &num, int target, int start, vector<int> &out,
           vector<vector<int>> &res) {
    if (target == 0) {
      res.push_back(out);
    } else if (target < 0) {
      return;
    } else {

      for (int i = start; i < num.size(); ++i) {
        if (i > start && num[i] == num[i - 1]) {
          continue;
        }
        out.push_back(num[i]);
        dfs(num, target - num[i], i + 1, out, res);
        out.pop_back();
      }
    }
  }
};

#ifdef DEBUG
int main() {
  Solution sol;

  sol.combinationSum2({7, 1, 2, 5, 1, 6, 10}, 8);
}
#endif
