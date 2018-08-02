#include <vector>
using namespace std;
/*
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (24.93%)
 * Total Accepted:    25.2K
 * Total Submissions: 100.9K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return
 * an array of the k digits.
 *
 * Note: You should try to optimize your time and space complexity.
 *
 * Example 1:
 *
 *
 * Input:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * Output:
 * [9, 8, 6, 5, 3]
 *
 * Example 2:
 *
 *
 * Input:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * Output:
 * [6, 7, 6, 0, 4]
 *
 * Example 3:
 *
 *
 * Input:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * Output:
 * [9, 8, 9]
 *
 *
 */

// https://www.youtube.com/watch?v=YYduNJfzWaA
class Solution {
  vector<int> maxNumber(const vector<int> &nums, int k) {
    vector<int> ans(k);
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      while (j > 0 && nums[i] > ans[j - 1] && nums.size() - i > k - j) {
        --j;
      }
      if (j < k) {
        ans[j++] = nums[i];
      }
    }
    return ans;
  }

  vector<int> maxNumber(const vector<int> &nums1, const vector<int> &nums2) {
    vector<int> ans(nums1.size() + nums2.size());
    auto s1 = nums1.cbegin();
    auto e1 = nums1.cend();
    auto s2 = nums2.cbegin();
    auto e2 = nums2.cend();
    int index = 0;
    while (s1 != e1 || s2 != e2) {
      ans[index++] = lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++;
    }
    return ans;
  }

public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> ans;
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
      ans = max(ans, maxNumber(maxNumber(nums1, i), maxNumber(nums2, k - i)));
    }
    return ans;
  }
};
