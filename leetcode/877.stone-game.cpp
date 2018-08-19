#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * [909] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (51.99%)
 * Total Accepted:    5.4K
 * Total Submissions: 10K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alex and Lee play a game with piles of stones.  There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 *
 * The objective of the game is to end with the most stones.  The total number
 * of stones is odd, so there are no ties.
 *
 * Alex and Lee take turns, with Alex starting first.  Each turn, a player
 * takes the entire pile of stones from either the beginning or the end of the
 * row.  This continues until there are no more piles left, at which point the
 * person with the most stones wins.
 *
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins
 * the game.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [5,3,4,5]
 * Output: true
 * Explanation:
 * Alex starts first, and can only take the first 5 or the last 5.
 * Say he takes the first 5, so that the row becomes [3, 4, 5].
 * If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10
 * points.
 * If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alex, so we
 * return true.
 *
 *
 *
 *
 * Note:
 *
 *
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles) is odd.
 *
 */
class Solution {
public:
  bool stoneGame(const vector<int> &piles) {
    int N = piles.size();

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 1; len <= N; ++len) {
      for (int start = 0, end = start + len - 1; end < N; ++start, ++end) {
        dp[start][end] =
            max(piles[start] - (start + 1 <= end ? dp[start + 1][end] : 0),
                piles[end] - (start <= end - 1 ? dp[start][end - 1] : 0));
      }
    }

    return dp[0][N - 1];
  }

  bool stoneGame1(vector<int> &piles) { return true; }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.stoneGame({5, 3, 4, 5});
}
#endif
