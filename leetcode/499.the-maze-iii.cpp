#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
/*
 * [499] The Maze III
 *
 * https://leetcode.com/problems/the-maze-iii/description/
 *
 * algorithms
 * Hard (34.17%)
 * Total Accepted:    5.8K
 * Total Submissions: 17K
 * Testcase Example:
 * '[[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]]\n[4,3]\n[0,1]'
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go
 * through empty spaces by rolling up (u), down (d), left (l) or right (r), but
 * it won't stop rolling until hitting a wall. When the ball stops, it could
 * choose the next direction. There is also a hole in this maze. The ball will
 * drop into the hole if it rolls on to the hole.
 *
 * ⁠Given the ball position, the hole position and the maze, find out how the
 * ball could drop into the hole by moving the shortest distance. The distance
 * is defined by the number of empty spaces traveled by the ball from the start
 * position (excluded) to the hole (included). Output the moving directions by
 * using 'u', 'd', 'l' and 'r'. Since there could be several different shortest
 * ways, you should output the lexicographically smallest way. If the ball
 * cannot reach the hole, output "impossible".
 *
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means
 * the empty space. You may assume that the borders of the maze are all walls.
 * The ball and the hole coordinates are represented by row and column
 * indexes.
 *
 *
 * Example 1
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 0 0 0
 * 1 1 0 0 1
 * 0 0 0 0 0
 * 0 1 0 0 1
 * 0 1 0 0 0
 *
 * Input 2: ball coordinate (rowBall, colBall) = (4, 3)
 * Input 3: hole coordinate (rowHole, colHole) = (0, 1)
 *
 * Output: "lul"
 * Explanation: There are two shortest ways for the ball to drop into the hole.
 * The first way is left -> up -> left, represented by "lul".
 * The second way is up -> left, represented by 'ul'.
 * Both ways have shortest distance 6, but the first way is lexicographically
 * smaller because 'l' < 'u'. So the output is "lul".
 *
 *
 *
 *
 *
 * Example 2
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 0 0 0
 * 1 1 0 0 1
 * 0 0 0 0 0
 * 0 1 0 0 1
 * 0 1 0 0 0
 *
 * Input 2: ball coordinate (rowBall, colBall) = (4, 3)
 * Input 3: hole coordinate (rowHole, colHole) = (3, 0)
 * Output: "impossible"
 * Explanation: The ball cannot reach the hole.
 *
 *
 *
 *
 * Note:
 *
 * There is only one ball and one hole in the maze.
 * Both the ball and hole exist on an empty space, and they will not be at the
 * same position initially.
 * The given maze does not contain border (like the red rectangle in the
 * example pictures), but you could assume the border of the maze are all
 * walls.
 * The maze contains at least 2 empty spaces, and the width and the height of
 * the maze won't exceed 30.
 *
 *
 */

vector<pair<char, pair<int, int>>> dirs{
    {'d', {1, 0}},
    {'l', {0, -1}},
    {'r', {0, 1}},
    {'u', {-1, 0}},
};

class Solution {
public:
  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball,
                         vector<int> &hole) {
    int numRows = maze.size();
    int numCols = maze[0].size();
    vector<vector<int>> dists(numRows,
                              vector<int>(numCols, numeric_limits<int>::max()));
    queue<pair<int, int>> q;
    unordered_map<int, string> m;
    dists[ball[0]][ball[1]] = 0;
    q.push({ball[0], ball[1]});
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      for (auto const &dir : dirs) {
        int newRow = t.first, newCol = t.second, dist = dists[newRow][newCol];
        string path = m[newRow * numCols + newCol];
        while (newRow >= 0 && newRow < numRows && newCol >= 0 &&
               newCol < numCols && maze[newRow][newCol] == 0 &&
               (newRow != hole[0] || newCol != hole[1])) {
          newRow += dir.second.first;
          newCol += dir.second.second;
          dist += 1;
        }
        if (newRow != hole[0] || newCol != hole[1]) {
          newRow -= dir.second.first;
          newCol -= dir.second.second;
          dist -= 1;
        }
        path.push_back(dir.first);
        if (dists[newRow][newCol] > dist) {
          dists[newRow][newCol] = dist;
          m[newRow * numCols + newCol] = path;
          if (newRow != hole[0] || newCol != hole[1]) {
            q.push({newRow, newCol});
          }
        } else if (dists[newRow][newCol] == dist &&
                   m[newRow * numCols + newCol].compare(path) > 0) {
          m[newRow * numCols + newCol] = path;
          if (newRow != hole[0] || newCol != hole[1]) {
            q.push({newRow, newCol});
          }
        }
      }
    }
    string res = m[hole[0] * numCols + hole[1]];
    return res.empty() ? "impossible" : res;
  }
};
