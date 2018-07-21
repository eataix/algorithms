#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [317] Shortest Distance from All Buildings
 *
 * https://leetcode.com/problems/shortest-distance-from-all-buildings/description/
 *
 * algorithms
 * Hard (34.94%)
 * Total Accepted:    25.8K
 * Total Submissions: 73.9K
 * Testcase Example:  '[[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]'
 *
 * You want to build a house on an empty land which reaches all buildings in
 * the shortest amount of distance. You can only move up, down, left and right.
 * You are given a 2D grid of values 0, 1 or 2, where:
 *
 *
 * Each 0 marks an empty land which you can pass by freely.
 * Each 1 marks a building which you cannot pass through.
 * Each 2 marks an obstacle which you cannot pass through.
 *
 *
 * Example:
 *
 *
 * Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
 *
 * 1 - 0 - 2 - 0 - 1
 * |   |   |   |   |
 * 0 - 0 - 0 - 0 - 0
 * |   |   |   |   |
 * 0 - 0 - 1 - 0 - 0
 *
 * Output: 7
 *
 * Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle
 * at (0,2),
 * ⁠            the point (1,2) is an ideal empty land to build a house, as
 * the total travel distance of 3+3+1=7 is minimal. So return 7.
 *
 * Note:
 * There will be at least one building. If it is not possible to build such
 * house according to the above rules, return -1.
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

public:
  int shortestDistance(const vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return -1;
    }

    int numRows = grid.size();
    int numCols = grid[0].size();

    vector<vector<int>> dists(numRows, vector<int>(numCols, 0));
    vector<vector<int>> reach(numRows, vector<int>(numCols, 0));

    int buildings = 0;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (grid[r][c] == 1) {
          buildings += 1;
          vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

          queue<pair<pair<int, int>, int>> q;
          q.push({{r, c}, 0});
          visited[r][c] = true;

          while (!q.empty()) {
            auto coord = q.front().first;
            auto dist = q.front().second;
            q.pop();
            auto currRow = coord.first;
            auto currCol = coord.second;

            reach[currRow][currCol] += 1;
            dists[currRow][currCol] += dist;

            for (auto dir : dirs) {
              int newR = currRow + dir.first;
              int newC = currCol + dir.second;

              if (newR >= 0 && newR < numRows && newC >= 0 && newC < numCols) {
                if (!visited[newR][newC] && grid[newR][newC] == 0) {
                  visited[newR][newC] = true;
                  q.push({{newR, newC}, dist + 1});
                }
              }
            }
          }
        }
      }
    }

    int minV = numeric_limits<int>::max();
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (grid[r][c] == 0 && reach[r][c] == buildings && dists[r][c] < minV) {
          minV = dists[r][c];
        }
      }
    }

    return minV == numeric_limits<int>::max() ? -1 : minV;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.shortestDistance(
              {{{1, 0, 2, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}}})
       << endl;
}
#endif
