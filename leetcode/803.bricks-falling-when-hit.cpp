#include <vector>
using namespace std;
/*
 * [821] Bricks Falling When Hit
 *
 * https://leetcode.com/problems/bricks-falling-when-hit/description/
 *
 * algorithms
 * Hard (22.67%)
 * Total Accepted:    2.5K
 * Total Submissions: 10.9K
 * Testcase Example:  '[[1,0,0,0],[1,1,1,0]]\n[[1,0]]'
 *
 * We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick
 * will not drop if and only if it is directly connected to the top of the
 * grid, or at least one of its (4-way) adjacent bricks will not drop.
 *
 * We will do some erasures sequentially. Each time we want to do the erasure
 * at the location (i, j), the brick (if it exists) on that location will
 * disappear, and then some other bricks may drop because of that erasure.
 *
 * numRowseturn an array representing the number of bricks that will drop after
 * each erasure in sequence.
 *
 *
 * Example 1:
 * Input:
 * grid = [[1,0,0,0],[1,1,1,0]]
 * hits = [[1,0]]
 * Output: [2]
 * Explanation:
 * If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop.
 * So we should return 2.
 *
 *
 * Example 2:
 * Input:
 * grid = [[1,0,0,0],[1,1,0,0]]
 * hits = [[1,1],[1,0]]
 * Output: [0,0]
 * Explanation:
 * When we erase the brick at (1, 0), the brick at (1, 1) has already
 * disappeared due to the last move. So each erasure will cause no bricks
 * dropping.  Note that the erased brick (1, 0) will not be counted as a
 * dropped brick.
 *
 *
 *
 * Note:
 *
 *
 * The number of rows and columns in the grid will be in the range [1,
 * 200].
 * The number of erasures will not exceed the area of the grid.
 * It is guaranteed that each erasure will be different from any other erasure,
 * and located inside the grid.
 * An erasure may refer to a location with no brick - if it does, no bricks
 * drop.
 *
 *
 */

class DSU {
  vector<int> parent;
  vector<int> rank;
  vector<int> sz;

public:
  DSU(int N) : parent(N), rank(N), sz(N, 1) {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void union_set(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr == yr)
      return;

    if (rank[xr] < rank[yr]) {
      swap(xr, yr);
    }
    if (rank[xr] == rank[yr]) {
      rank[xr]++;
    }

    parent[yr] = xr;
    sz[xr] += sz[yr];
  }

  int size(int x) { return sz[find(x)]; }

  int top() { return size(sz.size() - 1) - 1; }
};

class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    int numRows = grid.size(), numCols = grid[0].size();
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};

    auto A = grid;
    for (auto const &hit : hits) {
      A[hit[0]][hit[1]] = 0;
    }

    DSU dsu{numRows * numCols + 1};
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (A[r][c] == 1) {
          int i = r * numCols + c;
          if (r == 0)
            dsu.union_set(i, numRows * numCols);
          if (r > 0 && A[r - 1][c] == 1)
            dsu.union_set(i, (r - 1) * numCols + c);
          if (c > 0 && A[r][c - 1] == 1)
            dsu.union_set(i, r * numCols + c - 1);
        }
      }
    }
    int t = hits.size();
    vector<int> ans(t--);

    while (t >= 0) {
      int r = hits[t][0];
      int c = hits[t][1];
      int prenumRowsoof = dsu.top();
      if (grid[r][c] == 0) {
        t--;
      } else {
        int i = r * numCols + c;
        for (auto const &dir : dirs) {
          int nr = r + dir.first;
          int nc = c + dir.second;
          if (0 <= nr && nr < numRows && 0 <= nc && nc < numCols &&
              A[nr][nc] == 1)
            dsu.union_set(i, nr * numCols + nc);
        }
        if (r == 0)
          dsu.union_set(i, numRows * numCols);
        A[r][c] = 1;
        ans[t--] = max(0, dsu.top() - prenumRowsoof - 1);
      }
    }

    return ans;
  }
};
