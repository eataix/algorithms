class Solution {
public:
  /**
   * @param maze: the maze
   * @param start: the start
   * @param destination: the destination
   * @return: the shortest distance for the ball to stop at the destination
   */
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
                       vector<int> &destination) {
    if (maze.empty() || maze[0].empty()) {
      return -1;
    }

    int numRows = maze.size();
    int numCols = maze[0].size();
    vector<vector<int>> distances(
        numRows, vector<int>(numCols, numeric_limits<int>::max()));
    distances[start[0]][start[1]] = 0;
    dfs(maze, start[0], start[1], destination, distances);

    return distances[destination[0]][destination[1]] ==
                   numeric_limits<int>::max()
               ? -1
               : distances[destination[0]][destination[1]];
  }
  vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  void dfs(const vector<vector<int>> &maze, int row, int col,
           const vector<int> &destination, vector<vector<int>> &distances) {
    int numRows = maze.size();
    int numCols = maze[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
      return;
    }

    for (auto dir : dirs) {
      int newRow = row;
      int newCol = col;
      int dr = dir.first;
      int dc = dir.second;
      int distance = distances[row][col];
      while (newRow + dr >= 0 && newRow + dr < numRows && newCol + dc >= 0 &&
             newCol + dc < numCols && maze[newRow + dr][newCol + dc] == 0) {
        newRow += dr;
        newCol += dc;
        distance += 1;
      }
      if (distance < distances[newRow][newCol]) {
        distances[newRow][newCol] = distance;
        if (newRow != destination[0] || newCol != destination[1]) {
          dfs(maze, newRow, newCol, destination, distances);
        }
      }
    }
  }
};

class Solution {
public:
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  /**
   * @param maze: the maze
   * @param start: the start
   * @param destination: the destination
   * @return: the shortest distance for the ball to stop at the destination
   */
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
                       vector<int> &destination) {
    int numRows = maze.size();
    int numCols = maze[0].size();

    vector<vector<int>> dists(numRows,
                              vector<int>(numCols, numeric_limits<int>::max()));

    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    dists[start[0]][start[1]] = 0;

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      int currRow = curr.first;
      int currCol = curr.second;
      cout << currRow << " " << currCol << endl;

      for (auto dir : dirs) {
        int newRow = currRow;
        int newCol = currCol;
        int dist = dists[currRow][currCol];

        while (newRow >= 0 && newRow < numRows && newCol >= 0 &&
               newCol < numCols && maze[newRow][newCol] == 0) {
          newRow += dir.first;
          newCol += dir.second;
          dist += 1;
        }

        newRow -= dir.first;
        newCol -= dir.second;
        dist -= 1;

        if (dist < dists[newRow][newCol]) {
          dists[newRow][newCol] = dist;
          if (newRow != destination[0] || newCol != destination[1]) {
            q.push({newRow, newCol});
          }
        }
      }
    }
    int res = dists[destination[0]][destination[1]];
    return res == numeric_limits<int>::max() ? -1 : res;
  }
};
