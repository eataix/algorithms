#include <vector>
using namespace std;
/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (23.05%)
 * Total Accepted:    250.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 *
 * Example 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
class Solution {
public:
  double findMedianSortedArrays(const vector<int> &nums1,
                                const vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();

    int low = 0;
    int high = m;

    while (low <= high) {
      int partition1 = (low + high) / 2;
      int partition2 = (m + n + 1) / 2 - partition1;

      int maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
      int minRight1 = partition1 == m ? INT_MAX : nums1[partition1];

      int maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
      int minRight2 = partition2 == n ? INT_MAX : nums2[partition2];

      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
        if ((m + n) % 2 == 0) {
          return static_cast<double>(max(maxLeft1, maxLeft2) +
                                     min(minRight1, minRight2)) /
                 2;
        } else {
          return static_cast<double>(max(maxLeft1, maxLeft2));
        }
      } else if (maxLeft1 > minRight2) {
        high = partition1 - 1;
      } else {
        low = partition1 + 1;
      }
    }
  }
};
