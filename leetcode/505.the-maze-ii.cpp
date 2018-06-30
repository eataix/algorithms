#include <queue>
#include <vector>
using namespace std;
/*
 * [505] The Maze II
 *
 * https://leetcode.com/problems/the-maze-ii/description/
 *
 * algorithms
 * Medium (38.79%)
 * Total Accepted:    13.4K
 * Total Submissions: 34.6K
 * Testcase Example:
 * '[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]\n[0,4]\n[4,4]'
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go
 * through empty spaces by rolling up, down, left or right, but it won't stop
 * rolling until hitting a wall. When the ball stops, it could choose the next
 * direction.
 *
 * Given the ball's start position, the destination and the maze, find the
 * shortest distance for the ball to stop at the destination. The distance is
 * defined by the number of empty spaces traveled by the ball from the start
 * position (excluded) to the destination (included). If the ball cannot stop
 * at the destination, return -1.
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
 * Output: 12
 * Explanation: One shortest way is : left -> down -> left -> down -> right ->
 * down -> right.
 * ⁠            The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
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
 * Output: -1
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
  vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
                       vector<int> &destination) {
    int numRows = maze.size(), numCols = maze[0].size();
    vector<vector<int>> dists(numRows,
                              vector<int>(numCols, numeric_limits<int>::max()));
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    dists[start[0]][start[1]] = 0;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int row = t.first;
      int col = t.second;
      for (auto dir : dirs) {
        int newRow = row;
        int newCol = col;
        int dist = dists[t.first][t.second];
        while (newRow >= 0 && newRow < numRows && newCol >= 0 &&
               newCol < numCols && maze[newRow][newCol] == 0) {
          newRow += dir.first;
          newCol += dir.second;
          ++dist;
        }
        newRow -= dir.first;
        newCol -= dir.second;
        --dist;
        if (dist < dists[newRow][newCol]) {
          dists[newRow][newCol] = dist;
          if (newRow != destination[0] || newCol != destination[1]) {
            q.push({newRow, newCol});
          }
        }
      }
    }
    int res = dists[destination[0]][destination[1]];
    return (res == numeric_limits<int>::max()) ? -1 : res;
  }
};
