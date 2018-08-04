#include <string>
#include <vector>
using namespace std;
/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (34.48%)
 * Total Accepted:    106.7K
 * Total Submissions: 309.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * Example:
 *
 *
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 *
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 *
 *
 */
class Solution {
  bool isValid(const vector<int> &pos, int row, int col) {
    for (int i = 0; i < row; ++i) {
      if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
        return false;
      }
    }
    return true;
  }

  void dfs(vector<int> &pos, int row, vector<vector<string>> &res) {
    int n = pos.size();
    if (row == n) {
      vector<string> out(n, string(n, '.'));

      for (int i = 0; i < n; ++i) {
        out[i][pos[i]] = 'Q';
      }

      res.push_back(out);
    } else {
      for (int col = 0; col < n; ++col) {
        if (isValid(pos, row, col)) {
          pos[row] = col;
          dfs(pos, row + 1, res);
          pos[row] = -1;
        }
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> pos(n, -1);
    dfs(pos, 0, res);
    return res;
  }
};
