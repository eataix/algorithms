#include <vector>
using namespace std;
/*
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (36.25%)
 * Total Accepted:    32.8K
 * Total Submissions: 90.5K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower.
 *
 * However, when you guess a particular number x,  and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 *
 *
 * Example:
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = $21.
 *
 *
 *
 * Given a particular n ≥ 1, find out how much money you need to have to
 * guarantee a win.
 *
 * Credits:Special thanks to @agave and @StefanPochmann for adding this problem
 * and creating all test cases.
 */
class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; ++len) {
      for (int start = 0; start <= n; ++start) {
        auto end = start + len - 1;
        if (end > n) {
          break;
        }
        auto minV = numeric_limits<int>::max();
        for (auto piv = start; piv < end; ++piv) {
          auto v = piv + max(dp[start][piv - 1], dp[piv + 1][end]);
          minV = min(minV, v);
        }

        dp[start][end] = minV;
      }
    }

    return dp[1][n];
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.getMoneyAmount(2);
}
#endif
