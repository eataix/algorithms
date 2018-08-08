#include <algorithm>
#include <vector>
using namespace std;
/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.73%)
 * Total Accepted:    235.3K
 * Total Submissions: 592.3K
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;

    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      *it += carry;

      carry = *it / 10;
      *it %= 10;
    }

    if (carry > 0) {
      digits.insert(digits.begin(), carry);
    }
    return digits;
  }
};
