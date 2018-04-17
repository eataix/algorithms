#include <iostream>
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
    bool isEven = (nums1.size() + nums2.size()) % 2 == 0;
    int total = nums1.size() + nums2.size();

    if (isEven) {
      return ((double)findNthElement(nums1, nums2, total / 2) +
              findNthElement(nums1, nums2, total / 2 + 1)) /
             2;
    } else {
      return findNthElement(nums1, nums2, (total + 1) / 2);
    }
  }

  int findNthElement(const vector<int> &nums1, const vector<int> &nums2,
                     int target) {
    int i = 0;
    int j = 0;

    int currVal;
    for (int k = 1; k <= target; ++k) {
      if (i == nums1.size()) {
        currVal = nums2[j++];
      } else if (j == nums2.size()) {
        currVal = nums1[i++];
      } else if (nums1[i] < nums2[j]) {
        currVal = nums1[i++];
      } else {
        currVal = nums2[j++];
      }
    }
    return currVal;
  }
};

#ifdef DEBUG
int main() {
  vector<int> v1 = {1, 2};
  vector<int> v2 = {3, 4};
  Solution sol;
  cout << sol.findMedianSortedArrays(v1, v2) << endl;
}
#endif