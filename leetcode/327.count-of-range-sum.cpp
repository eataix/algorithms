#include <algorithm>
#include <vector>
using namespace std;
/*
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (30.99%)
 * Total Accepted:    25.6K
 * Total Submissions: 82.7K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * Given an integer array nums, return the number of range sums that lie in
 * [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * A naive algorithm of O(n2) is trivial. You MUST do better than that.
 *
 * Example:
 *
 *
 * Input: nums = [-2,5,-1], lower = -2, upper = 2,
 * Output: 3
 * Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective
 * sums are: -2, -1, 2.
 *
 *
 */
class Solution {
  int countWhileMergeSort(vector<long> &sums, int start, int end, int lower,
                          int upper) {
    if (end - start <= 1) {
      return 0;
    }

    int mid = (start + end) / 2;
    int m = mid;
    int n = mid;
    int count = countWhileMergeSort(sums, start, mid, lower, upper) +
                countWhileMergeSort(sums, mid, end, lower, upper);

    for (int i = start; i < mid; ++i) {
      while (m < end && sums[m] - sums[i] < lower) {
        m += 1;
      }
      while (n < end && sums[n] - sums[i] <= upper) {
        n += 1;
      }
      count += n - m;
    }
    inplace_merge(sums.begin() + start, sums.begin() + mid, sums.begin() + end);
    return count;
  }

public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    vector<long> sums(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      sums[i + 1] = sums[i] + nums[i];
    }
    return countWhileMergeSort(sums, 0, n + 1, lower, upper);
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.countRangeSum({-2, 5, -1}, -2, 2);
}
#endif
