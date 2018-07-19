#include <iostream>
#include <vector>
using namespace std;
/*
 * [361] Bomb Enemy
 *
 * https://leetcode.com/problems/bomb-enemy/description/
 *
 * algorithms
 * Medium (40.77%)
 * Total Accepted:    25.6K
 * Total Submissions: 62.9K
 * Testcase Example:  '[["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]'
 *
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0'
 * (the number zero), return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted
 * point until it hits the wall since the wall is too strong to be destroyed.
 * ⁠Note that you can only put the bomb at an empty cell.
 *
 * Example:
 *
 * For the given grid
 *
 * 0 E 0 0
 * E 0 W E
 * 0 E 0 0
 *
 * return 3. (Placing a bomb at (1,1) kills 3 enemies)
 *
 *
 *
 * Credits:Special thanks to @memoryless for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
  int maxKilledEnemies(const vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int numRows = grid.size();
    int numCols = grid[0].size();
    int res = 0;

    int rowhits;
    vector<int> colHits(numCols, 0);

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (c == 0 || grid[r][c - 1] == 'W') {
          rowhits = 0;
          for (int k = c; k < numCols && grid[r][k] != 'W'; ++k) {
            rowhits += grid[r][k] == 'E';
          }
        }
        if (r == 0 || grid[r - 1][c] == 'W') {
          colHits[c] = 0;
          for (int k = r; k < numRows && grid[k][c] != 'W'; ++k) {
            colHits[c] += grid[k][c] == 'E';
          }
        }
        if (grid[r][c] == '0') {
          res = max(res, rowhits + colHits[c]);
        }
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.maxKilledEnemies({{'0'}, {'0'}, {'0'}}) << endl;
}
#endif