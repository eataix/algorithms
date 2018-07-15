#include <vector>
using namespace std;
/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (45.87%)
 * Total Accepted:    66.6K
 * Total Submissions: 145.1K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 *
 *
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 *
 *
 * Example:
 *
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 *
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */
class Solution {
  int search_le(const vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int r = n - 1;
    int c = 0;
    int res = 0;

    while (r >= 0 && c < n) {
      if (matrix[r][c] <= target) {
        res += r + 1;
        c += 1;
      } else {
        r -= 1;
      }
    }
    return res;
  }

public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int left = matrix.front().front();
    int right = matrix.back().back();

    while (left < right) {
      int mid = left + (right - left) / 2;
      int cnt = search_le(matrix, mid);
      if (cnt < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
