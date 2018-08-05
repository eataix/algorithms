/*
 * [806] Domino and Tromino Tiling
 *
 * https://leetcode.com/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (33.17%)
 * Total Accepted:    4.3K
 * Total Submissions: 12.9K
 * Testcase Example:  '3'
 *
 * We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape.
 * These shapes may be rotated.
 *
 *
 * XX  <- domino
 *
 * XX  <- "L" tromino
 * X
 *
 *
 * Given N, how many ways are there to tile a 2 x N board? Return your answer
 * modulo 10^9 + 7.
 *
 * (In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.)
 *
 *
 *
 * Example:
 * Input: 3
 * Output: 5
 * Explanation:
 * The five different ways are listed below, different letters indicates
 * different tiles:
 * XYZ XXZ XYY XXY XYY
 * XYZ YYZ XZZ XYY XXY
 *
 * Note:
 *
 *
 * N  will be in range [1, 1000].
 *
 *
 *
 */
class Solution {
public:
  int numTilings(int N) {
    int md = 1e9;
    md += 7;

    int p3 = -1;
    int p2 = 0;
    int p1 = 1;

    for (int n = 1; n <= N; ++n) {
      int curr = static_cast<int>((static_cast<long long>(p1) * 2L + p3) % md);
      p3 = p2;
      p2 = p1;
      p1 = curr;
    }
    return p1;
  }
};