#include <string>
#include <vector>
using namespace std;
/*
 * [247] Strobogrammatic Number II
 *
 * https://leetcode.com/problems/strobogrammatic-number-ii/description/
 *
 * algorithms
 * Medium (41.33%)
 * Total Accepted:    31.2K
 * Total Submissions: 75.4K
 * Testcase Example:  '2'
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * Example:
 *
 *
 * Input:  n = 2
 * Output: ["11","69","88","96"]
 *
 *
 */
class Solution {
  vector<string> helper(int n, int m) {
    if (n == 0) {
      return {""};
    }

    if (n == 1) {
      return {"0", "1", "8"};
    }

    auto list = helper(n - 2, m);

    vector<string> res;
    for (auto const &s : list) {
      if (n != m) {
        res.push_back("0" + s + "0");
      }

      res.push_back("1" + s + "1");
      res.push_back("6" + s + "9");
      res.push_back("8" + s + "8");
      res.push_back("9" + s + "6");
    }
    return res;
  }

public:
  vector<string> findStrobogrammatic(int n) { return helper(n, n); }
};
