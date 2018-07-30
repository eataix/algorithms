#include <string>
#include <vector>
using namespace std;
/*
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (38.83%)
 * Total Accepted:    23K
 * Total Submissions: 59.3K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 *
 *
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 *
 *
 *
 * Note:
 *
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 *
 *
 *
 * Example 1:
 *
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 *
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 *
 *
 *
 * Example 2:
 *
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 *
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 *
 *
 */
class Solution {
  pair<int, int> count(const string &str) {
    int numZeros = 0;
    int numOnes = 0;
    for (char ch : str) {
      if (ch == '0') {
        numZeros += 1;
      } else {
        numOnes += 1;
      }
    }
    return {numZeros, numOnes};
  }

public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto const &str : strs) {
      auto counts = count(str);
      auto numZeros = counts.first;
      auto numOnes = counts.second;

      for (int i = m; i >= numZeros; --i) {
        for (int j = n; j >= numOnes; --j) {
          dp[i][j] = max(dp[i][j], dp[i - numZeros][j - numOnes] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
