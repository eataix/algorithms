#include <set>
#include <stack>
#include <vector>
using namespace std;
/*
 * [794] Swim in Rising Water
 *
 * https://leetcode.com/problems/swim-in-rising-water/description/
 *
 * algorithms
 * Hard (44.16%)
 * Total Accepted:    5.6K
 * Total Submissions: 12.6K
 * Testcase Example:  '[[0,2],[1,3]]'
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that
 * point (i,j).
 *
 * Now rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and
 * only if the elevation of both squares individually are at most t. You can
 * swim infinite distance in zero time. Of course, you must stay within the
 * boundaries of the grid during your swim.
 *
 * You start at the top left square (0, 0). What is the least time until you
 * can reach the bottom right square (N-1, N-1)?
 *
 * Example 1:
 *
 *
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have
 * a higher elevation than t = 0.
 *
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 * ⁠0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 *
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 *
 *
 * Note:
 *
 *
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool possible(int T, const vector<vector<int>> &grid) {
    int N = grid.size();

    set<pair<int, int>> seen;
    seen.insert({0, 0});

    stack<pair<int, int>> s;
    s.push({0, 0});

    while (!s.empty()) {
      auto coord = s.top();
      s.pop();
      auto r = coord.first;
      auto c = coord.second;
      if (r == N - 1 && c == N - 1) {
        return true;
      }

      for (auto const &dir : dirs) {
        int nr = r + dir.first;
        int nc = c + dir.second;

        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !seen.count({nr, nc}) &&
            grid[nr][nc] <= T) {
          s.push({nr, nc});
          seen.insert({nr, nc});
        }
      }
    }
    return false;
  }

public:
  int swimInWater(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return -1;
    }

    int N = grid.size();

    int lo = grid[0][0];
    int hi = N * N;

    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (!possible(mi, grid)) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return lo;
  }
};
