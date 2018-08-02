#include <cmath>
#include <string>
using namespace std;
/*
 * [483] Smallest Good Base
 *
 * https://leetcode.com/problems/smallest-good-base/description/
 *
 * algorithms
 * Hard (33.88%)
 * Total Accepted:    8K
 * Total Submissions: 23.5K
 * Testcase Example:  '"13"'
 *
 * For an integer n, we call k>=2 a good base of n, if all digits of n base k
 * are 1.
 * Now given a string representing n, you should return the smallest good base
 * of n in string format.
 *
 * Example 1:
 *
 * Input: "13"
 * Output: "3"
 * Explanation: 13 base 3 is 111.
 *
 *
 *
 * Example 2:
 *
 * Input: "4681"
 * Output: "8"
 * Explanation: 4681 base 8 is 11111.
 *
 *
 *
 * Example 3:
 *
 * Input: "1000000000000000000"
 * Output: "999999999999999999"
 * Explanation: 1000000000000000000 base 999999999999999999 is 11.
 *
 *
 *
 * Note:
 *
 * The range of n is [3, 10^18].
 * The string representing n is always valid and will not have leading zeros.
 *
 *
 */
class Solution {

  typedef unsigned long long ull;

public:
  string smallestGoodBase(string n) {
    ull num = (ull)stoll(n);
    int maxlen = log(num) / log(2) + 1;
    for (int k = maxlen; k >= 3; --k) {
      ull b = pow(num, 1.0 / (k - 1)), sum = 1, cur = 1;
      for (int i = 1; i < k; ++i) {
        sum += (cur *= b);
      }
      if (sum == num) {
        return to_string(b);
      }
    }
    return to_string(num - 1);
  }
};
