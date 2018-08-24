#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (47.27%)
 * Total Accepted:    39.9K
 * Total Submissions: 84.4K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 *
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 *
 *
 */
class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>> &points) {
    int res = 0;
    for (int i = 0; i < points.size(); ++i) {
      auto p = points[i];
      unordered_map<int, int> m;
      for (int j = 0; j < points.size(); ++j) {
        if (i == j) {
          continue;
        }
        auto q = points[j];
        int dy = p.second - q.second;
        int dx = p.first - q.first;

        int key = dy * dy + dx * dx;
        m[key] += 1;
      }

      for (auto &kv : m) {
        if (kv.second > 1) {
          res += kv.second * (kv.second - 1);
        }
      }
    }
    return res;
  }
};
