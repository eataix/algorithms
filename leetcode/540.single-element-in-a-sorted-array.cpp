#include <vector>
using namespace std;
/*
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (55.85%)
 * Total Accepted:    31.7K
 * Total Submissions: 56.8K
 * Testcase Example:  '[1,1,2]'
 *
 *
 * Given a sorted array consisting of only integers where every element appears
 * twice except for one element which appears once. Find this single element
 * that appears only once.
 *
 *
 * Example 1:
 *
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 *
 *
 *
 * Example 2:
 *
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 *
 *
 *
 * Note:
 * Your solution should run in O(log n) time and O(1) space.
 *
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/100754/Java-Binary-Search-short-(7l)-O(log(n))-w-explanations
 */
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
      int mid = (start + end) / 2;
      mid = mid / 2 * 2;

      if (nums[mid] != nums[mid + 1]) {
        end = mid;
      } else {
        start = mid + 2;
      }
    }

    return nums[start];
  }
};
