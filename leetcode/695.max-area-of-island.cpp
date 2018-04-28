#include <vector>
using namespace std;
/*
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Easy (51.76%)
 * Total Accepted:    26.9K
 * Total Submissions: 51.9K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)  You
 * may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array.
 * (If there is no island, the maximum area is 0.)
 *
 * Example 1:
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Given the above grid, return 6.
 *
 * Note the answer is not 11, because the island must be connected
 * 4-directionally.
 *
 *
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 *
 *
 * Note:
 * The length of each dimension in the given grid does not exceed 50.
 *
 */
const vector<pair<int, int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }

    int m = grid.size();
    int n = grid[0].size();
    int res = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 1) {
          continue;
        }
        int count = 0;
        dfs(grid, i, j, count, res);
      }
    }
    return res;
  }

  void dfs(vector<vector<int>> &grid, int i, int j, int &count, int &res) {
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) {
      return;
    }
    count += 1;
    res = max(res, count);
    grid[i][j] *= -1;
    for (const auto &dir : dirs) {
      dfs(grid, i + dir.first, j + dir.second, count, res);
    }
  }
};
