#include <vector>
using namespace std;
/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (45.00%)
 * Total Accepted:    233.6K
 * Total Submissions: 519K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 * https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
 */
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> out;
    backtrack(res, out, nums, 0);
    return res;
  }

  void backtrack(vector<vector<int>> &res, vector<int> &out,
                 const vector<int> &nums, int start) {
    res.push_back(out);

    for (int i = start; i < nums.size(); ++i) {
      out.push_back(nums[i]);
      backtrack(res, out, nums, i + 1);
      out.pop_back();
    }
  }
};
