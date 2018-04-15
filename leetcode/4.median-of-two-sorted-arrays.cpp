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
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size() - 1;
        int n = nums2.size() - 1;
        return findMedianSortedArrays(nums1, 0, m, nums2, 0, n);
    }

    double findMedianSortedArrays(const vector<int> &nums1, int start1, int end1, const vector<int> &nums2, int start2, int end2)
    {
        int middle1 = (end1 - start1) / 2;
        int middle2 = (end2 - start2) / 2;
    }
};