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
  int shortestDistance(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return -1;
    }

    int numRows = grid.size();
    int numCols = grid[0].size();

    auto total = grid;

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (grid[r][c] == 1) {
          auto dist = grid;
          queue<pair<pair<int, int>, int>> q;
          q.push({{r, c}, 0});

          while (!q.empty()) {
            auto coord = q.front().first;
            auto dist = q.front().second;
            q.pop();

            for (auto dir : dirs) {
              int newR = coord.first + dir.first;
              int newC = coord.second + dir.second;
            }
          }
        }
      }
    }
  }
};
