#include <vector>
using namespace std;
/*
 * [265] Paint House II
 *
 * https://leetcode.com/problems/paint-house-ii/description/
 *
 * algorithms
 * Hard (39.03%)
 * Total Accepted:    34K
 * Total Submissions: 87.2K
 * Testcase Example:  '[[1,5,3],[2,9,4]]'
 *
 * There are a row of n houses, each house can be painted with one of the k
 * colors. The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the
 * same color.
 *
 * The cost of painting each house with a certain color is represented by a n x
 * k cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color 0; costs[1][2] is the cost of painting house 1 with color 2, and so
 * on... Find the minimum cost to paint all houses.
 *
 * Note:
 * All costs are positive integers.
 *
 * Example:
 *
 *
 * Input: [[1,5,3],[2,9,4]]
 * Output: 5
 * Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum
 * cost: 1 + 4 = 5;
 * Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 +
 * 2 = 5.
 *
 *
 * Follow up:
 * Could you solve it in O(nk) runtime?
 *
 */
class Solution {
public:
  int minCostII(vector<vector<int>> &costs) {
    if (costs.empty() || costs[0].empty()) {
      return 0;
    }
    vector<vector<int>> dp = costs;

    int min1 = -1;
    int min2 = -1;

    for (int i = 0; i < dp.size(); ++i) {
      int last1 = min1;
      int last2 = min2;
      min1 = -1;
      min2 = -1;

      for (int j = 0; j < dp[i].size(); ++j) {
        if (j != last1) {
          dp[i][j] += last1 < 0 ? 0 : dp[i - 1][last1];

        } else {
          dp[i][j] += last2 < 0 ? 0 : dp[i - 1][last2];
        }

        if (min1 < 0 || dp[i][j] < dp[i][min1]) {
          min2 = min1;
          min1 = j;
        } else if (min2 < 0 || dp[i][j] < dp[i][min2]) {
          min2 = j;
        }
      }
    }

    return dp.back()[min1];
  }
};
