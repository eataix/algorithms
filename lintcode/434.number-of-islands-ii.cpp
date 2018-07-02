/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  int findRoot(const vector<int> parents, int id) {
    if (parents[id] == id) {
      return id;
    } else {
      return findRoot(parents, parents[id]);
    }
  }

public:
  /**
   * @param n: An integer
   * @param m: An integer
   * @param operators: an array of point
   * @return: an integer array
   */
  vector<int> numIslands2(int n, int m, vector<Point> &operators) {
    vector<int> parents(n * m, -1);
    vector<int> res;
    int island = 0;
    for (auto op : operators) {
      int id = m * op.x + op.y;
      island += 1;
      parents[id] = id;

      for (auto dir : dirs) {
        int newR = op.x + dir.first;
        int newC = op.y + dir.second;
        int newId = newR * m + newC;

        if (newR < 0 || newR >= n || newC < 0 || newC >= m ||
            parents[newId] == -1) {
          continue;
        }

        int p = findRoot(parents, newId);
        int q = findRoot(parents, id);

        if (p != q) {
          parents[p] = q;
          island -= 1;
        }
      }
      res.push_back(island);
    }
    return res;
  }
};
