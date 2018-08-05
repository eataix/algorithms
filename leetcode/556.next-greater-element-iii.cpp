#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
/*
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (28.85%)
 * Total Accepted:    15.5K
 * Total Submissions: 53.6K
 * Testcase Example:  '12'
 *
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 *
 * Example 1:
 *
 *
 * Input: 12
 * Output: 21
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 21
 * Output: -1
 *
 *
 *
 *
 */
class Solution {
public:
  int nextGreaterElement(int n) {
    string nums = to_string(n);
    if (nums.size() == 1) {
      return -1;
    }

    int k = -1;

    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        k = i;
        break;
      }
    }

    if (k == -1) {
      return -1;
    }

    int l = -1;

    for (int i = nums.size() - 1; i > k; --i) {
      if (nums[i] > nums[k]) {
        l = i;
        break;
      }
    }

    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());

    long long next = stoll(nums);

    return next == n || next > numeric_limits<int>::max() ? -1 : next;
  }
};
