#include <iostream>
#include <utility>
#include <vector>
using namespace std;
class Solution {
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  void dfs(vector<vector<bool>> &grid, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return;
    }

    if (!grid[row][col]) {
      return;
    }

    grid[row][col] = false;

    for (auto const &direction : directions) {
      int newRow = row + direction.first;
      int newCol = col + direction.second;
      dfs(grid, newRow, newCol);
    }
  }

public:
  /**
   * @param grid: a boolean 2D matrix
   * @return: an integer
   */
  int numIslands(vector<vector<bool>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int res = 0;

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (grid[row][col]) {
          dfs(grid, row, col);
          res += 1;
        }
      }
    }

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;

  vector<vector<bool>> v{{1, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1},
                         {0, 0, 0, 1, 1},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1}};
  cout << sol.numIslands(v) << endl;
}
#endif
