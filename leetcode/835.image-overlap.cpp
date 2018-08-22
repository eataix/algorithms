#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [864] Image Overlap
 *
 * https://leetcode.com/problems/image-overlap/description/
 *
 * algorithms
 * Medium (38.95%)
 * Total Accepted:    3.5K
 * Total Submissions: 9K
 * Testcase Example:  '[[1,1,0],[0,1,0],[0,1,0]]\n[[0,0,0],[0,1,1],[0,0,1]]'
 *
 * Two images A and B are given, represented as binary, square matrices of the
 * same size.  (A binary matrix has only 0s and 1s as values.)
 *
 * We translate one image however we choose (sliding it left, right, up, or
 * down any number of units), and place it on top of the other image.  After,
 * the overlap of this translation is the number of positions that have a 1 in
 * both images.
 *
 * (Note also that a translation does not include any kind of rotation.)
 *
 * What is the largest possible overlap?
 *
 * Example 1:
 *
 *
 * Input: A = [[1,1,0],
 * ⁠           [0,1,0],
 * [0,1,0]]
 * B = [[0,0,0],
 * [0,1,1],
 * [0,0,1]]
 * Output: 3
 * Explanation: We slide A to right by 1 unit and down by 1 unit.
 *
 * Notes: 
 *
 *
 * 1 <= A.length = A[0].length = B.length = B[0].length <= 30
 * 0 <= A[i][j], B[i][j] <= 1
 *
 *
 */

class Solution {
public:
  int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B) {
    if (A.empty() || A[0].empty()) {
      return 0;
    }

    int numRows = A.size();
    int numCols = A[0].size();

    auto id = [&numCols](int r, int c) { return r * numCols * 2 + c; };

    vector<int> LA;
    vector<int> LB;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (A[r][c] == 1) {
          LA.push_back(id(r, c));
        }
        if (B[r][c] == 1) {
          LB.push_back(id(r, c));
        }
      }
    }
    unordered_map<int, int> m;
    for (int i : LA) {
      for (int j : LB) {
        m[i - j] += 1;
      }
    }
    int res = 0;
    for (auto const &kv : m) {
      res = max(res, kv.second);
    }
    return res;
  }
};
