#include <vector>
using namespace std;
/*
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (29.37%)
 * Total Accepted:    72.2K
 * Total Submissions: 245.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 *
 * Note: The algorithm should run in linear time and in O(1) space.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: [3]
 *
 * Example 2:
 *
 *
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 *
 */
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    vector<int> res;
    if (nums.size() <= 1) {
      return nums;
    }
    int m{0};
    int n{0};
    int cm{0};
    int cn{0};
    for (int num : nums) {
      if (num == m) {
        cm += 1;
      } else if (num == n) {
        cn += 1;
      } else if (cm == 0) {
        m = num;
        cm = 1;
      } else if (cn == 0) {
        n = num;
        cn = 1;
      } else {
        cm -= 1;
        cn -= 1;
      }
    }
    cm = cn = 0;
    for (int num : nums) {
      if (num == m) {
        cm += 1;
      } else if (num == n) {
        cn += 1;
      }
    }

    if (cm > nums.size() / 3) {
      res.push_back(m);
    }
    if (cn > nums.size() / 3) {
      res.push_back(n);
    }
    return res;
  }
};
