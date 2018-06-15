#include <string>
#include <unordered_map>

using namespace std;
/*
 * [246] Strobogrammatic Number
 *
 * https://leetcode.com/problems/strobogrammatic-number/description/
 *
 * algorithms
 * Easy (40.37%)
 * Total Accepted:    36.7K
 * Total Submissions: 91K
 * Testcase Example:  '"69"'
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 *
 * Write a function to determine if a number is strobogrammatic. The number is
 * represented as a string.
 *
 * Example 1:
 *
 *
 * Input:  "69"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:  "88"
 * Output: true
 *
 * Example 3:
 *
 *
 * Input:  "962"
 * Output: false
 *
 */
class Solution {
public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> m{
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    int l = 0;
    int r = num.size() - 1;

    while (l <= r) {
      char cl = num[l];
      char cr = num[r];

      if (m.find(cl) == m.cend()) {
        return false;
      }

      if (m[cl] != cr) {
        return false;
      }

      l += 1;
      r -= 1;
    }
    return true;
  }
};
