#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
/*
 * [370] Range Addition
 *
 * https://leetcode.com/problems/range-addition/description/
 *
 * algorithms
 * Medium (57.73%)
 * Total Accepted:    19K
 * Total Submissions: 32.9K
 * Testcase Example:  '5\n[[1,3,2],[2,4,3],[0,2,-2]]'
 *
 * Assume you have an array of length n initialized with all 0's and are given
 * k update operations.
 *
 * Each operation is represented as a triplet: [startIndex, endIndex, inc]
 * which increments each element of subarray A[startIndex ... endIndex]
 * (startIndex and endIndex inclusive) with inc.
 *
 * Return the modified array after all k operations were executed.
 *
 * Example:
 *
 * Given:
 *
 * ⁠   length = 5,
 * ⁠   updates = [
 * ⁠       [1,  3,  2],
 * ⁠       [2,  4,  3],
 * ⁠       [0,  2, -2]
 * ⁠   ]
 *
 * Output:
 *
 * ⁠   [-2, 0, 3, 5, 3]
 *
 *
 *
 * Explanation:
 *
 * Initial state:
 * [ 0, 0, 0, 0, 0 ]
 *
 * After applying operation [1, 3, 2]:
 * [ 0, 2, 2, 2, 0 ]
 *
 * After applying operation [2, 4, 3]:
 * [ 0, 2, 5, 5, 3 ]
 *
 * After applying operation [0, 2, -2]:
 * [-2, 0, 3, 5, 3 ]
 *
 *
 *
 * Credits:Special thanks to @vinod23 for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    vector<int> result(length, 0);
    for (auto const &update : updates) {
      int start = update[0];
      int end = update[1];
      int val = update[2];

      result[start] += val;

      if (end < length - 1) {
        result[end + 1] -= val;
      }
    }

    partial_sum(result.begin(), result.end(), result.begin());
    return result;
  }
};
