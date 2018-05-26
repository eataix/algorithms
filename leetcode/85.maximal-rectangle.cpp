#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (29.89%)
 * Total Accepted:    87.6K
 * Total Submissions: 293.1K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 *
 *
 */
class Solution {
private:
  int maximalHist(vector<int> hist) {
    int res = 0;
    hist.push_back(0);

    stack<int> st;
    for (int i = 0; i < hist.size(); ++i) {
      while (!st.empty() && hist[st.top()] > hist[i]) {
        int top = st.top();
        st.pop();
        res = max(res, hist[top] * (st.empty() ? i : (i - st.top() - 1)));
      }
      st.push(i);
    }
    return res;
  }

public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int res = 0;
    vector<int> heights(numCols);
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        heights[c] = matrix[r][c] == '0' ? 0 : (1 + heights[c]);
      }
      res = max(res, maximalHist(heights));
    }
    return res;
  }
};
