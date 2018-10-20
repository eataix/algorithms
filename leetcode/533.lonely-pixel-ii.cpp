#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [533] Lonely Pixel II
 *
 * https://leetcode.com/problems/lonely-pixel-ii/description/
 *
 * algorithms
 * Medium (45.49%)
 * Total Accepted:    7.1K
 * Total Submissions: 15.6K
 * Testcase Example:
 * '[["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","W","B","W","B","W"]]\n3'
 *
 * Given a picture consisting of black and white pixels, and a positive integer
 * N, find the number of black pixels located at some specific row R and column
 * C that align with all the following rules:
 *
 *
 * ⁠Row R and column C both contain exactly N black pixels.
 * ⁠For all rows that have a black pixel at column C, they should be exactly
 * the same as row R
 *
 *
 * The picture is represented by a 2D char array consisting of 'B' and 'W',
 * which means black and white pixels respectively.
 *
 * Example:
 *
 * Input:
 * [['W', 'B', 'W', 'B', 'B', 'W'],
 * ⁠['W', 'B', 'W', 'B', 'B', 'W'],
 * ⁠['W', 'B', 'W', 'B', 'B', 'W'],
 * ⁠['W', 'W', 'B', 'W', 'B', 'W']]
 *
 * N = 3
 * Output: 6
 * Explanation: All the bold 'B' are the black pixels we need (all 'B's at
 * column 1 and 3).
 * ⁠       0    1    2    3    4    5         column
 * index
 * 0    [['W', 'B', 'W', 'B', 'B', 'W'],
 * 1     ['W', 'B', 'W', 'B', 'B', 'W'],
 * 2     ['W', 'B', 'W', 'B', 'B', 'W'],
 * 3     ['W', 'W', 'B', 'W', 'B', 'W']]
 * row index
 *
 * Take 'B' at row R = 0 and column C = 1 as an example:
 * Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels.
 * Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row
 * 2. They are exactly the same as row R = 0.
 *
 *
 *
 *
 * Note:
 *
 * The range of width and height of the input 2D array is [1,200].
 *
 *
 */

class Solution {
public:
  int findBlackPixel(vector<vector<char>> &picture, int N) {
    if (picture.empty() || picture[0].empty())
      return 0;
    int m = picture.size(), n = picture[0].size(), res = 0;
    vector<int> colCnt(n, 0);
    unordered_map<string, int> u;
    for (int i = 0; i < m; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          ++colCnt[j];
          ++cnt;
        }
      }
      if (cnt == N)
        ++u[string(picture[i].begin(), picture[i].end())];
    }
    for (auto a : u) {
      if (a.second != N)
        continue;
      for (int i = 0; i < n; ++i) {
        res += (a.first[i] == 'B' && colCnt[i] == N) ? N : 0;
      }
    }
    return res;
  }
};