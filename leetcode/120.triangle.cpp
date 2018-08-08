#include <vector>
using namespace std;
/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (35.27%)
 * Total Accepted:    135.1K
 * Total Submissions: 382.9K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */
class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<int> dp = triangle.back();
    int lvls = triangle.size();

    for (int l = lvls - 2; l >= 0; --l) {
      for (int i = 0; i <= l; ++i) {
        dp[i] = min(dp[i], dp[i + 1]) + triangle[l][i];
      }
    }
    return dp[0];
  }
};
