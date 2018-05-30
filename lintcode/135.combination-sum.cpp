#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param candidates: A list of integers
   * @param target: An integer
   * @return: A list of lists of integers
   */
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    combinationSumDFS(candidates, target, 0, tmp, res);
    return res;
  }

  void combinationSumDFS(const vector<int> &candidates, int target, int start,
                         vector<int> &working, vector<vector<int>> &res) {
#ifdef DEBUG
    cout << "target: " << target << " start: " << start << endl;
    for (int i : working) {
      cout << i << " ";
    }
    cout << endl;
#endif

    if (target == 0) {
#ifdef DEBUG
      cout << "Solution: ";
      for (int i : working) {
        cout << i << " ";
      }
      cout << endl;
#endif
      res.push_back(working);
      return;
    }

    if (target < 0) {
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      working.push_back(candidates[i]);
      combinationSumDFS(candidates, target - candidates[i], i, working, res);
      working.pop_back();
    }
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> v1{1, 2};
  sol.combinationSum(v1, 2);
}
#endif
