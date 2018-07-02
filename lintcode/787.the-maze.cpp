class Solution {
public:
  /**
   * @param maze: the maze
   * @param start: the start
   * @param destination: the destination
   * @return: whether the ball could stop at the destination
   */
  bool hasPath(vector<vector<int>> &maze, vector<int> &start,
               vector<int> &destination) {
    if (maze.empty() || maze[0].empty()) {
      return false;
    }
    int numRows = maze.size();
    int numCols = maze[0].size();

    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

    dfs(maze, start[0], start[1], destination, visited);

    return visited[destination[0]][destination[1]];
  }
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  void dfs(const vector<vector<int>> &maze, int row, int col,
           const vector<int> &destination, vector<vector<bool>> &visited) {
    int numRows = maze.size();
    int numCols = maze[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols ||
        visited[row][col]) {
      return;
    }
    visited[row][col] = true;
    if (row == destination[0] && col == destination[1]) {
      return;
    }
    for (auto dir : dirs) {
      int newRow = row;
      int newCol = col;
      int dr = dir.first;
      int dc = dir.second;

      while (newRow + dr >= 0 && newRow + dr < numRows && newCol + dc >= 0 &&
             newCol + dc < numCols && maze[newRow + dr][newCol + dc] == 0) {
        newRow += dr;
        newCol += dc;
      }
      dfs(maze, newRow, newCol, destination, visited);
    }
  }
};
