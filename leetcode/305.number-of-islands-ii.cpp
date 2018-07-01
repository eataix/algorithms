#include <utility>
#include <vector>
using namespace std;
/*
 * [305] Number of Islands II
 *
 * https://leetcode.com/problems/number-of-islands-ii/description/
 *
 * algorithms
 * Hard (39.72%)
 * Total Accepted:    35.2K
 * Total Submissions: 88.5K
 * Testcase Example:  '3\n3\n[[0,0],[0,1],[1,2],[2,1]]'
 *
 * A 2d grid map of m rows and n columns is initially filled with water. We may
 * perform an addLand operation which turns the water at position (row, col)
 * into a land. Given a list of positions to operate, count the number of
 * islands after each addLand operation. An island is surrounded by water and
 * is formed by connecting adjacent lands horizontally or vertically. You may
 * assume all four edges of the grid are all surrounded by water.
 *
 * Example:
 *
 *
 * Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
 * Output: [1,1,2,3]
 *
 *
 * Explanation:
 *
 * Initially, the 2d grid grid is filled with water. (Assume 0 represents water
 * and 1 represents land).
 *
 *
 * 0 0 0
 * 0 0 0
 * 0 0 0
 *
 *
 * Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
 *
 *
 * 1 0 0
 * 0 0 0   Number of islands = 1
 * 0 0 0
 *
 *
 * Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
 *
 *
 * 1 1 0
 * 0 0 0   Number of islands = 1
 * 0 0 0
 *
 *
 * Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
 *
 *
 * 1 1 0
 * 0 0 1   Number of islands = 2
 * 0 0 0
 *
 *
 * Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
 *
 *
 * 1 1 0
 * 0 0 1   Number of islands = 3
 * 0 1 0
 *
 *
 * Follow up:
 *
 * Can you do it in time complexity O(k log mn), where k is the length of the
 * positions?
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  int findRoot(const vector<int> &roots, int id) {
    if (id == roots[id]) {
      return id;
    } else {
      return findRoot(roots, roots[id]);
    }
  }

public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>> &positions) {
    vector<int> res;
    int island = 0;
    vector<int> roots(m * n, -1);

    for (auto pos : positions) {
      int id = n * pos.first + pos.second;
      roots[id] = id;
      island += 1;

      for (auto dir : dirs) {
        int newR = pos.first + dir.first;
        int newC = pos.second + dir.second;
        int newId = newR * n + newC;

        if (newR < 0 || newR >= m || newC < 0 || newC >= n ||
            roots[newId] == -1) {
          continue;
        }

        int p = findRoot(roots, newId);
        int q = findRoot(roots, id);

        if (p != q) {
          roots[p] = q;
          island -= 1;
        }
      }

      res.push_back(island);
    }

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<pair<int, int>> v{{3, 1}};
  sol.numIslands2(4, 2, v);
}
#endif
