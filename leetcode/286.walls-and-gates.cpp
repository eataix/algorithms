#include <queue>
#include <utility>
#include <vector>
using namespace std;
/*
 * [286] Walls and Gates
 *
 * https://leetcode.com/problems/walls-and-gates/description/
 *
 * algorithms
 * Medium (45.93%)
 * Total Accepted:    50.2K
 * Total Submissions: 109.4K
 * Testcase Example:
 * '[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]'
 *
 * You are given a m x n 2D grid initialized with these three possible
 * values.
 *
 *
 * -1 - A wall or an obstacle.
 * 0 - A gate.
 * INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to
 * represent INF as you may assume that the distance to a gate is less than
 * 2147483647.
 *
 *
 * Fill each empty room with the distance to its nearest gate. If it is
 * impossible to reach a gate, it should be filled with INF.
 *
 * Example: 
 *
 * Given the 2D grid:
 *
 *
 * INF  -1  0  INF
 * INF INF INF  -1
 * INF  -1 INF  -1
 * ⁠ 0  -1 INF INF
 *
 *
 * After running your function, the 2D grid should be:
 *
 *
 * ⁠ 3  -1   0   1
 * ⁠ 2   2   1  -1
 * ⁠ 1  -1   2  -1
 * ⁠ 0  -1   3   4
 *
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    if (rooms.empty() || rooms[0].empty()) {
      return;
    }

    int numRows = rooms.size();
    int numCols = rooms[0].size();

    queue<pair<int, int>> q;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (rooms[r][c] == 0) {
          q.push({r, c});
        }
      }
    }

    while (!q.empty()) {
      auto rc = q.front();
      q.pop();
      auto row = rc.first;
      auto col = rc.second;

      for (auto const &dir : dirs) {
        auto newRow = row + dir.first;
        auto newCol = col + dir.second;

        if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
            newCol < numCols) {
          if (rooms[newRow][newCol] == numeric_limits<int>::max()) {
            rooms[newRow][newCol] = rooms[row][col] + 1;
            q.push({newRow, newCol});
          }
        }
      }
    }
  }
};
