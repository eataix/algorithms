#include <string>
using namespace std;
/*
 * [248] Strobogrammatic Number III
 *
 * https://leetcode.com/problems/strobogrammatic-number-iii/description/
 *
 * algorithms
 * Hard (33.11%)
 * Total Accepted:    12.4K
 * Total Submissions: 37.3K
 * Testcase Example:  '"50"\n"100"'
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 *
 * Write a function to count the total strobogrammatic numbers that exist in
 * the range of low <= num <= high.
 *
 * Example:
 *
 *
 * Input: low = "50", high = "100"
 * Output: 3
 * Explanation: 69, 88, and 96 are three strobogrammatic numbers.
 *
 * Note:
 * Because the range might be a large number, the low and high numbers are
 * represented as string.
 *
 */
class Solution {
  void find(const string &low, const string &high, const string &out,
            int &res) {
    if (out.size() >= low.size() && out.size() <= high.size()) {
      if ((out.size() == low.size() && out.compare(low) < 0) ||
          (out.size() == high.size() && out.compare(high) > 0)) {
        return;
      }

      if (!(out.size() > 1 && out[0] == '0')) {
        res += 1;
      }
    }

    if (out.size() + 2 > high.size()) {
      return;
    }

    find(low, high, "0" + out + "0", res);
    find(low, high, "1" + out + "1", res);
    find(low, high, "6" + out + "9", res);
    find(low, high, "8" + out + "8", res);
    find(low, high, "9" + out + "6", res);
  }

public:
  int strobogrammaticInRange(string low, string high) {
    int res = 0;
    find(low, high, "", res);
    find(low, high, "0", res);
    find(low, high, "1", res);
    find(low, high, "8", res);
    return res;
  }
};
