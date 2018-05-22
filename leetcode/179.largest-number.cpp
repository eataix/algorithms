#include <string>
#include <vector>
using namespace std;
/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (23.53%)
 * Total Accepted:    93.2K
 * Total Submissions: 396K
 * Testcase Example:  '[3, 30, 34, 5, 9]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * Example 1:
 *
 *
 * Input: [10,2]
 * Output: 210
 *
 * Example 2:
 *
 *
 * Input: [3,30,34,5,9]
 * Output: 9534330
 *
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 */
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    string res;
    sort(nums.begin(), nums.end(), [](int a, int b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    for (auto const &num : nums) {
      res += to_string(num);
    }
    return res[0] == '0' ? "0" : res;
  }
};
