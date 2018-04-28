#include <algorithm>
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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> mergedArray = mergeArrays(nums1, nums2);
    if (mergedArray.size() % 2 == 0) {
      int mid1 = (mergedArray.size() - 1) / 2;
      int mid2 = (mergedArray.size() + 1) / 2;
      return (static_cast<double>(mergedArray[mid1]) +
              static_cast<double>(mergedArray[mid2])) /
             2;
    } else {
      int mid = (mergedArray.size() - 1) / 2;
      return static_cast<double>(mergedArray[mid]);
    }
  }

  vector<int> mergeArrays(const vector<int> &nums1, const vector<int> &nums2) {
    int i = 0;
    int j = 0;
    vector<int> res;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] <= nums2[j]) {
        res.push_back(nums1[i]);
        i++;
      } else {
        res.push_back(nums2[j]);
        j++;
      }
    }

    while (i < nums1.size()) {
      res.push_back(nums1[i++]);
    }

    while (j < nums2.size()) {
      res.push_back(nums2[j++]);
    }
    return res;
  }
};
