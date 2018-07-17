#include <vector>
using namespace std;
/*
 * [900] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (44.09%)
 * Total Accepted:    2.3K
 * Total Submissions: 5.1K
 * Testcase Example:  '1'
 *
 * Starting with a positive integer N, we reorder the digits in any order
 * (including the original order) such that the leading digit is not zero.
 *
 * Return true if and only if we can do this in a way such that the resulting
 * number is a power of 2.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 10
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 4:
 *
 *
 * Input: 24
 * Output: false
 *
 *
 *
 * Example 5:
 *
 *
 * Input: 46
 * Output: true
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 10^9
 *
 *
 *
 *
 *
 *
 *
 */
class Solution {
  vector<int> count(int N) {
    vector<int> res(10, 0);

    while (N > 0) {
      res[N % 10] += 1;
      N /= 10;
    }

    return res;
  }

public:
  bool reorderedPowerOf2(int N) {
    auto A = count(N);

    for (int i = 0; i < 31; ++i) {
      if (A == count(1 << i)) {
        return true;
      }
    }
    return false;
  }
};
