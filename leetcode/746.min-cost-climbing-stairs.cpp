#include <vector>
using namespace std;
/*
 * [747] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (43.46%)
 * Total Accepted:    27.6K
 * Total Submissions: 63.5K
 * Testcase Example:  '[0,0,0,0]'
 *
 *
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
 * indexed).
 *
 * Once you pay the cost, you can either climb one or two steps. You need to
 * find minimum cost to reach the top of the floor, and you can either start
 * from the step with index 0, or the step with index 1.
 *
 *
 * Example 1:
 *
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the
 * top.
 *
 *
 *
 * Example 2:
 *
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
 * cost[3].
 *
 *
 *
 * Note:
 *
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 *
 *
 */
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    cost.push_back(0);
    cost.insert(begin(cost), 0);
    vector<int> dp(n + 2, numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 0; i < dp.size() - 1; ++i) {
      dp[i + 1] = min(dp[i + 1], dp[i] + cost[i]);
      if (i < dp.size() - 2) {

        dp[i + 2] = min(dp[i + 2], dp[i] + cost[i]);
      }
    }

    return dp.back();
  }
};
