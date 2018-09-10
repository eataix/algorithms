class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

public:
  /**
   * @param grid: the 2D grid
   * @return: the shortest distance
   */
  int shortestDistance(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int numRows = grid.size();
    int numCols = grid[0].size();

    vector<vector<int>> distances(numRows, vector<int>(numCols, 0));
    vector<vector<int>> reach(numRows, vector<int>(numCols, 0));

    int numBuildings = 0;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (grid[r][c] == 1) {
          numBuildings += 1;
          queue<pair<pair<int, int>, int>> q;
          vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

          q.push({{r, c}, 0});
          visited[r][c] = true;

          while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto coord = t.first;
            auto dist = t.second;
            auto currR = coord.first;
            auto currC = coord.second;

            if (grid[currR][currC] == 0) {
              distances[currR][currC] += dist;
              reach[currR][currC] += 1;
            }

            for (auto const &dir : dirs) {
              auto newR = currR + dir.first;
              auto newC = currC + dir.second;

              if (newR >= 0 && newR < numRows && newC >= 0 && newC < numCols &&
                  grid[newR][newC] == 0 && !visited[newR][newC]) {
                q.push({{newR, newC}, dist + 1});
                visited[newR][newC] = true;
              }
            }
          }
        }
      }
    }

    int minDist = numeric_limits<int>::max();
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (grid[r][c] == 0 && reach[r][c] == numBuildings &&
            distances[r][c] < minDist) {
          minDist = distances[r][c];
        }
      }
    }
    return minDist;
  }
};