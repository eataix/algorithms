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
 * Return an array representing the number of bricks that will drop after
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

class UnionFind {
  vector<int> parents;
  vector<int> sizes;
  vector<int> ranks;

public:
  UnionFind(int n) : parents(n), sizes(n, 1), ranks(n, 0) {
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
  }

  int find_set(int i) {
    if (parents[i] != i) {
      parents[i] = find_set(parents[i]);
    }
    return parents[i];
  }

  void union_set(int i, int j) {
    auto p = find_set(i);
    auto q = find_set(j);
    if (p == q) {
      return;
    }

    if (ranks[p] < ranks[q]) {
      swap(p, q);
    }

    if (ranks[p] == ranks[q]) {
      ranks[p] += 1;
    }

    parents[q] = p;
    sizes[p] += sizes[q];
  }

  int size(int i) { return sizes[find_set(i)]; }
};
class Solution {
public:
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    auto A = grid;
    for (auto const &h : hits) {
      A[h[0]][h[1]] = 0;
    }

    UnionFind uf{numRows * numCols + 1};
    auto ID = [&numCols](int r, int c) { return r * numCols + c; };
    const int SB = numRows * numCols;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (A[r][c] == 1) {
          if (r == 0) {
            uf.union_set(ID(r, c), SB);
          }
          if (r > 0 && A[r - 1][c] == 1) {
            uf.union_set(ID(r, c), ID(r - 1, c));
          }
          if (c > 0 && A[r][c - 1] == 1) {
            uf.union_set(ID(r, c), ID(r, c - 1));
          }
        }
      }
    }
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> res;
    for (auto it = hits.crbegin(); it != hits.crend(); ++it) {
      auto r = (*it)[0];
      auto c = (*it)[1];

      if (grid[r][c] == 0) {
        res.push_back(0);
        continue;
      }
      int pre = uf.size(SB);

      for (auto const &dir : dirs) {
        auto newR = r + dir.first;
        auto newC = c + dir.second;

        if (newR >= 0 && newR < numRows && newC >= 0 && newC < numCols &&
            A[newR][newC] == 1) {
          uf.union_set(ID(newR, newC), ID(r, c));
        }
      }
      if (r == 0) {
        uf.union_set(ID(r, c), SB);
      }
      A[r][c] = 1;
      res.push_back(max(0, uf.size(SB) - pre - 1));
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
