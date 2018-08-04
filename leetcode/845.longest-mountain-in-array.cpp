#include <vector>
using namespace std;
/*
 * [875] Longest Mountain in Array
 *
 * https://leetcode.com/problems/longest-mountain-in-array/description/
 *
 * algorithms
 * Medium (31.21%)
 * Total Accepted:    5.5K
 * Total Submissions: 17.7K
 * Testcase Example:  '[2,1,4,7,3,2,5]'
 *
 * Let's call any (contiguous) subarray B (of A) a mountain if the following
 * properties hold:
 *
 *
 * B.length >= 3
 * There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] <
 * B[i] > B[i+1] > ... > B[B.length - 1]
 *
 *
 * (Note that B could be any subarray of A, including the entire array A.)
 *
 * Given an array A of integers, return the length of the longest mountain. 
 *
 * Return 0 if there is no mountain.
 *
 * Example 1:
 *
 *
 * Input: [2,1,4,7,3,2,5]
 * Output: 5
 * Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: [2,2,2]
 * Output: 0
 * Explanation: There is no mountain.
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 *
 *
 * Follow up:
 *
 *
 * Can you solve it using only one pass?
 * Can you solve it in O(1) space?
 *
 *
 *
 * https://leetcode.com/problems/longest-mountain-in-array/discuss/135593/C++JavaPython-1-pass-and-O(1)-space
 */
class Solution {
public:
  int longestMountain(vector<int> &A) {
    int res = 0;
    int up = 0;
    int down = 0;

    for (int i = 1; i < A.size(); ++i) {
      if (A[i - 1] == A[i] || (down > 0 && A[i - 1] < A[i])) {
        up = down = 0;
      }
      up += A[i - 1] < A[i];
      down += A[i - 1] > A[i];

      if (up > 0 && down > 0) {
        res = max(res, up + down + 1);
      }
    }
    return res;
  }

  int longestMountain2(vector<int> &A) {
    int n = A.size();
    int res = 0;
    vector<int> up(n, 0);
    vector<int> down(n, 0);
    for (int i = n - 2; i >= 0; --i) {
      if (A[i] > A[i + 1]) {
        down[i] = down[i + 1] + 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (i > 0 && A[i] > A[i - 1]) {
        up[i] = up[i - 1] + 1;
      }
      if (up[i] && down[i]) {
        res = max(res, up[i] + down[i] + 1);
      }
    }
    return res;
  }
};
