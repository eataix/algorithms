#include <vector>
using namespace std;
/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (32.13%)
 * Total Accepted:    229.6K
 * Total Submissions: 714.7K
 * Testcase Example:  '[1]\n1\n[]\n0'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 */
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> nums3(m + n);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        nums3[k++] = nums1[i++];
      } else {
        nums3[k++] = nums2[j++];
      }
    }
    while (i < m) {
      nums3[k++] = nums1[i++];
    }
    while (j < n) {
      nums3[k++] = nums2[j++];
    }
    for (int i = 0; i < m + n; ++i) {
      nums1[i] = nums3[i];
    }
  }
};
