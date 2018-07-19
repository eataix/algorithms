#include <utility>
#include <vector>
using namespace std;
/*
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (35.07%)
 * Total Accepted:    28.9K
 * Total Submissions: 82.3K
 * Testcase Example:
 * '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 *
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 *
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 *
 * Note:
 *
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 *
 *
 * Example:
 *
 * Given the following 5x5 matrix:
 *
 * ⁠ Pacific ~   ~   ~   ~   ~
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 *
 * Return:
 *
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 *
 *
 */
class Solution {
  void dfs(const vector<vector<int>> &matrix, vector<vector<bool>> &visited,
           int pre, int r, int c) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    if (r < 0 || r >= numRows || c < 0 || c >= numCols || visited[r][c] ||
        matrix[r][c] < pre) {
      return;
    }

    visited[r][c] = true;
    dfs(matrix, visited, matrix[r][c], r + 1, c);
    dfs(matrix, visited, matrix[r][c], r - 1, c);
    dfs(matrix, visited, matrix[r][c], r, c + 1);
    dfs(matrix, visited, matrix[r][c], r, c - 1);
  }

public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }

    vector<pair<int, int>> res;
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    vector<vector<bool>> pacific(numRows, vector<bool>(numCols, false));
    vector<vector<bool>> atlantic(numRows, vector<bool>(numCols, false));

    for (int r = 0; r < numRows; ++r) {
      dfs(matrix, pacific, numeric_limits<int>::min(), r, 0);
      dfs(matrix, atlantic, numeric_limits<int>::min(), r, numCols - 1);
    }

    for (int c = 0; c < numCols; ++c) {
      dfs(matrix, pacific, numeric_limits<int>::min(), 0, c);
      dfs(matrix, atlantic, numeric_limits<int>::min(), numRows - 1, c);
    }

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (pacific[r][c] && atlantic[r][c]) {
          res.push_back({r, c});
        }
      }
    }
    return res;
  }
};
