#include <queue>
using namespace std;
/*
 * [490] The Maze
 *
 * https://leetcode.com/problems/the-maze/description/
 *
 * algorithms
 * Medium (43.78%)
 * Total Accepted:    15.6K
 * Total Submissions: 35.7K
 * Testcase Example:
 * '[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]\n[0,4]\n[4,4]'
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go
 * through empty spaces by rolling up, down, left or right, but it won't stop
 * rolling until hitting a wall. When the ball stops, it could choose the next
 * direction.
 *
 * Given the ball's start position, the destination and the maze, determine
 * whether the ball could stop at the destination.
 *
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means
 * the empty space. You may assume that the borders of the maze are all walls.
 * The start and destination coordinates are represented by row and column
 * indexes.
 *
 *
 * Example 1
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 *
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (4, 4)
 *
 * Output: true
 * Explanation: One possible way is : left -> down -> left -> down -> right ->
 * down -> right.
 *
 *
 *
 *
 *
 * Example 2
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 *
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (3, 2)
 *
 * Output: false
 * Explanation: There is no way for the ball to stop at the destination.
 *
 *
 *
 *
 * Note:
 *
 * There is only one ball and one destination in the maze.
 * Both the ball and the destination exist on an empty space, and they will not
 * be at the same position initially.
 * The given maze does not contain border (like the red rectangle in the
 * example pictures), but you could assume the border of the maze are all
 * walls.
 * The maze contains at least 2 empty spaces, and both the width and height of
 * the maze won't exceed 100.
 *
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start,
               vector<int> &destination) {
    if (maze.empty() || maze[0].empty()) {
      return true;
    }

    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<pair<int, int>> q;

    q.push({start[0], start[1]});
    visited[start[0]][start[1]] = true;

    while (!q.empty()) {
      auto rc = q.front();
      q.pop();
      if (rc.first == destination[0] && rc.second == destination[1]) {
        return true;
      }

      for (auto dir : dirs) {
        int newR = rc.first;
        int newC = rc.second;

        while (newR >= 0 && newR < rows && newC >= 0 && newC < cols &&
               maze[newR][newC] == 0) {
          newR += dir.first;
          newC += dir.second;
        }

        newR -= dir.first;
        newC -= dir.second;

        if (!visited[newR][newC]) {
          visited[newR][newC] = true;
          q.push({newR, newC});
        }
      }
    }
    return false;
  }
};
