#include <string>
using namespace std;
/*
 * [793] Swap Adjacent in LR String
 *
 * https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
 *
 * algorithms
 * Medium (29.35%)
 * Total Accepted:    5.2K
 * Total Submissions: 17.7K
 * Testcase Example:  '"X"\n"L"'
 *
 * In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
 * move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". Given the starting string start
 * and the ending string end, return True if and only if there exists a
 * sequence of moves to transform one string to the other.
 *
 * Example:
 *
 *
 * Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
 * Output: True
 * Explanation:
 * We can transform start to end following these steps:
 * RXXLRXRXL ->
 * XRXLRXRXL ->
 * XRLXRXRXL ->
 * XRLXXRRXL ->
 * XRLXXRRLX
 *
 *
 * Note:
 *
 *
 * 1 <= len(start) = len(end) <= 10000.
 * Both start and end will only consist of characters in {'L', 'R', 'X'}.
 *
 */
class Solution {
public:
  bool canTransform(string start, string end) {
    int N = start.size();
    int i = -1;
    int j = -1;

    while (++i < N && ++j < N) {
      while (i < N && start[i] == 'X') {
        i += 1;
      }

      while (j < N && end[j] == 'X') {
        j += 1;
      }

      if ((i < N) ^ (j < N)) {
        return false;
      }

      if (i < N && j < N) {
        if (start[i] != end[j] || (start[i] == 'L' && i < j) ||
            (start[i] == 'R' && i > j)) {
          return false;
        }
      }
    }

    return true;
  }
};
