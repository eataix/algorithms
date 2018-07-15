#include <vector>
using namespace std;
/*
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.60%)
 * Total Accepted:    65.4K
 * Total Submissions: 165.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 *
 *
 * Formally the function should:
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1
 * else return false.
 *
 *
 *
 * Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 *
 *
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 *
 *
 * Given [5, 4, 3, 2, 1],
 * return false.
 *
 *
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    long long c1 = numeric_limits<long long>::max();
    long long c2 = numeric_limits<long long>::max();

    for (int num : nums) {
      if (num <= c1) {
        c1 = num;
      } else if (num <= c2) {
        c2 = num;
      } else {
        return true;
      }
    }

    return false;
  }
};
