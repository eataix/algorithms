#include <algorithm>
#include <vector>
using namespace std;
/*
 * [256] Paint House
 *
 * https://leetcode.com/problems/paint-house/description/
 *
 * algorithms
 * Easy (46.39%)
 * Total Accepted:    37.6K
 * Total Submissions: 81K
 * Testcase Example:  '[[17,2,17],[16,16,5],[14,3,19]]'
 *
 * There are a row of n houses, each house can be painted with one of the three
 * colors: red, blue or green. The cost of painting each house with a certain
 * color is different. You have to paint all the houses such that no two
 * adjacent houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by a n x
 * 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color red; costs[1][2] is the cost of painting house 1 with color green, and
 * so on... Find the minimum cost to paint all houses.
 *
 * Note:
 * All costs are positive integers.
 *
 * Example:
 *
 *
 * Input: [[17,2,17],[16,16,5],[14,3,19]]
 * Output: 10
 * Explanation: Paint house 0 into blue, paint house 1 into green, paint house
 * 2 into blue.
 * Minimum cost: 2 + 5 + 3 = 10.
 *
 *
 */
class Solution {
public:
  int minCost(vector<vector<int>> &costs) {
    if (costs.empty()) {
      return 0;
    }

    for (size_t i = 1; i < costs.size(); ++i) {
      costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
      costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
      costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
    }

    return min(costs.back()[0], min(costs.back()[1], costs.back()[2]));
  }
};
