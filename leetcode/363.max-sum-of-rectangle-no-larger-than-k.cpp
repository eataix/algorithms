#include <set>
#include <vector>
using namespace std;
/*
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (33.95%)
 * Total Accepted:    21.1K
 * Total Submissions: 62.1K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 *
 * Example:
 * Given matrix = [
 * ⁠ [1,  0, 1],
 * ⁠ [0, -2, 3]
 * ]
 * k = 2
 *
 *
 *
 * The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2
 * is the max number no larger than k (k = 2).
 *
 * Note:
 *
 * The rectangle inside the matrix must have an area > 0.
 * What if the number of rows is much larger than the number of columns?
 *
 *
 *
 * Credits:Special thanks to @fujiaozhu for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
  int maxSumSubmatrix(const vector<vector<int>> &matrix, int k) {
    if (matrix.empty()) {
      return 0;
    }

    int numRows = matrix.size();
    int numCols = matrix[0].size();

    int res = numeric_limits<int>::min();
    for (int l = 0; l < numCols; ++l) {
      vector<int> sums(numRows, 0);

      for (int r = l; r < numCols; ++r) {
        for (int i = 0; i < numRows; ++i) {
          sums[i] += matrix[i][r];
        }

        set<int> s;
        s.insert(0);
        int currSum = 0;
        int currMax = numeric_limits<int>::min();

        for (int sum : sums) {
          currSum += sum;
          auto it = s.lower_bound(currSum - k);

          if (it != s.cend()) {
            currMax = max(currMax, currSum - *it);
          }
          s.insert(currSum);
        }
        res = max(res, currMax);
      }
    }
    return res;
  }
};
