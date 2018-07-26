#include <queue>
#include <vector>
using namespace std;
/*
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (33.09%)
 * Total Accepted:    22.2K
 * Total Submissions: 67.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 * Example 1:
 * Input:
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 * Output:
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 *
 *
 * Example 2:
 * Input:
 *
 * 0 0 0
 * 0 1 0
 * 1 1 1
 *
 * Output:
 *
 * 0 0 0
 * 0 1 0
 * 1 2 1
 *
 *
 *
 * Note:
 *
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 *
 *
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return matrix;
    }
    vector<vector<int>> res = matrix;
    int numRows = res.size();
    int numCols = res[0].size();
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

    queue<pair<pair<int, int>, int>> q;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (res[r][c] == 0) {
          q.push({{r, c}, 0});
          visited[r][c] = true;
        }
      }
    }

    while (!q.empty()) {
      auto coord = q.front().first;
      auto dist = q.front().second;
      q.pop();

      auto r = coord.first;
      auto c = coord.second;
      res[r][c] = dist;

      for (auto const &dir : dirs) {
        auto newR = r + dir.first;
        auto newC = c + dir.second;

        if (newR >= 0 && newR < numRows && newC >= 0 && newC < numCols &&
            matrix[newR][newC] == 1 && !visited[newR][newC]) {
          q.push({{newR, newC}, dist + 1});
          visited[newR][newC] = true;
        }
      }
    }
    return res;
  }
};
