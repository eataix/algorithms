#include <algorithm>
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
class Solution {
  unordered_map<char, pair<int, int>> dirs{
      {'u', {-1, 0}}, {'d', {1, 0}}, {'l', {0, -1}}, {'r', {0, 1}}};

public:
  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball,
                         vector<int> &hole) {
    if (maze.empty() || maze[0].empty()) {
      return "impossible";
    }

    int numRows = maze.size();
    int numCols = maze[0].size();

    vector<vector<int>> distances(
        numRows, vector<int>(numCols, numeric_limits<int>::max()));
    vector<vector<char>> directions(numRows, vector<char>(numCols, ' '));
    vector<vector<pair<int, int>>> parents(numRows,
                                           vector<pair<int, int>>(numCols));

    queue<pair<int, int>> q;

    q.push({ball[0], ball[1]});
    distances[ball[0]][ball[1]] = 0;

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      int currRow = curr.first;
      int currCol = curr.second;

      cout << currRow << " " << currCol << endl;
      for (auto const &dir : dirs) {
        int newRow = currRow;
        int newCol = currCol;
        int dist = distances[currRow][currCol];

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

        if (dist < distances[newRow][newCol]) {
          distances[newRow][newCol] = dist;
          directions[newRow][newCol] = dir.first;
          parents[newRow][newCol] = {currRow, currCol};
          if (newRow != hole[0] || newCol != hole[1]) {
            q.push({newRow, newCol});
          }
        }
      }
    }

    if (distances[hole[0]][hole[1]] == numeric_limits<int>::max()) {
      return "impossible";
    } else {
      string res;
      int row = hole[0];
      int col = hole[1];

      while (directions[row][col] != ' ') {
        res += directions[row][col];

        auto p = parents[row][col];
        row = p.first;
        col = p.second;
      }

      reverse(res.begin(), res.end());
      return res;
    }
  }
};
