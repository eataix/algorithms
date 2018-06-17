class Solution {
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  /**
   * @param grid: a 2D array
   * @return: the perimeter of the island
   */
  int islandPerimeter(vector<vector<int>> &grid) {
    if (grid.size() == 0) {
      return 0;
    }
    int n = grid.size();
    int m = grid[0].size();
    int total = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          total += 4;
          if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            total -= 2;
          }
          if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            total -= 2;
          }
        }
      }
    }
    return total;
  }

  int islandPerimeter2(vector<vector<int>> &grid) {

    int count = 0;
    for (int row = 0; row < grid.size(); ++row) {
      for (int col = 0; col < grid[0].size(); ++col) {
        if (grid[row][col] == 1) {
          for (auto d : directions) {
            int newRow = row + d.first;
            int newCol = col + d.second;

            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
                newCol < grid[0].size()) {
              if (grid[newRow][newCol] == 0) {
                count += 1;
              }
            } else {
              count += 1;
            }
          }
        }
      }
    }
    return count;
  }
};
