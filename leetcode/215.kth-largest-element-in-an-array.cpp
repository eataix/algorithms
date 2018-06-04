#include <vector>
using namespace std;
/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (40.74%)
 * Total Accepted:    208.3K
 * Total Submissions: 511.1K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test
 * cases.
 *
 */
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    k = nums.size() - 1;

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int j = partition(nums, left, right);

      if (j < k) {
        left = j + 1;
      } else if (j > k) {
        right = j - 1;
      } else {
        break;
      }
    }

    return nums[k];
  }

  int partition(vector<int> elements, int low, int high) {
    int pivot = elements[low];

    int i = low - 1;
    int j = high + 1;

    for (;;) {
      do {
        i += 1;
      } while (elements[i] < pivot);

      do {
        j -= 1;
      } while (elements[j] > pivot);

      if (i >= j) {
        return j - 1;
      }

      swap(elements[i], elements[j]);
    }
  }
};
