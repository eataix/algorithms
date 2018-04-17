#include <vector>
using namespace std;
/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (36.62%)
 * Total Accepted:    171.2K
 * Total Submissions: 467.4K
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
vector<vector<int>> delta{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0) {
      return 0;
    }
    int res = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '1') {
          dfs(i, j, grid, n, m);
          res += 1;
        }
      }
    }
    return res;
  }

  void dfs(int x, int y, vector<vector<char>> &grid, const int n, const int m) {
    grid[x][y] = '0';

    for (auto d : delta) {
      int newX = x + d[0];
      int newY = y + d[1];
      if (0 <= newX && newX < n && 0 <= newY && newY < m &&
          grid[newX][newY] == '1') {
        dfs(newX, newY, grid, n, m);
      }
    }
    return;
  }
};
