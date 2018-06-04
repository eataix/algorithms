#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param nums: A set of numbers
   * @return: A list of lists
   */
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> out;
    sort(nums.begin(), nums.end());
    bt(res, out, nums, 0);
    return res;
  }

  void bt(vector<vector<int>> &res, vector<int> &out, const vector<int> &nums,
          int start) {
    res.push_back(out);

    for (int i = start; i < nums.size(); ++i) {
      out.push_back(nums[i]);
      bt(res, out, nums, i + 1);
      out.pop_back();
    }
  }
};