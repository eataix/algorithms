#include <queue>
#include <vector>
using namespace std;
/*
 * [407] Trapping Rain Water II
 *
 * https://leetcode.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (37.80%)
 * Total Accepted:    18.9K
 * Total Submissions: 49.9K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * Given an m x n matrix of positive integers representing the height of each
 * unit cell in a 2D elevation map, compute the volume of water it is able to
 * trap after raining.
 *
 *
 * Note:
 * Both m and n are less than 110. The height of each unit cell is greater than
 * 0 and is less than 20,000.
 *
 *
 * Example:
 *
 * Given the following 3x6 height map:
 * [
 * ⁠ [1,4,3,1,3,2],
 * ⁠ [3,2,1,3,2,4],
 * ⁠ [2,3,3,2,3,1]
 * ]
 *
 * Return 4.
 *
 *
 *
 *
 *
 * The above image represents the elevation map
 * [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
 *
 *
 *
 *
 * After the rain, water is trapped between the blocks. The total volume of
 * water trapped is 4.
 *
 */
class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    if (heightMap.empty() || heightMap[0].empty()) {
      return 0;
    }
    int numRows = heightMap.size();
    int numCols = heightMap[0].size();

    typedef pair<int, pair<int, int>> cell;
    priority_queue<cell, vector<cell>, greater<cell>> q;
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (r == 0 || r == numRows - 1 || c == 0 || c == numCols - 1) {
          if (!visited[r][c]) {
            q.push({heightMap[r][c], {r, c}});
          }
          visited[r][c] = true;
        }
      }
    }

    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int res = 0;

    while (!q.empty()) {
      auto cell = q.top();
      q.pop();

      auto value = cell.first;
      auto coord = cell.second;
      auto r = coord.first;
      auto c = coord.second;

      for (auto const &dir : dirs) {
        auto nr = r + dir.first;
        auto nc = c + dir.second;

        if (nr < 0 || nr >= numRows || nc < 0 || nc >= numCols ||
            visited[nr][nc]) {
          continue;
        }

        res += max(0, value - heightMap[nr][nc]);
        q.push({max(value, heightMap[nr][nc]), {nr, nc}});
        visited[nr][nc] = true;
      }
    }
    return res;
  }
};
