#include <vector>
using namespace std;
/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (20.18%)
 * Total Accepted:    107.7K
 * Total Submissions: 533.7K
 * Testcase Example:
 * '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 * Example:
 *
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 *
 * After running your function, the board should be:
 *
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 * Explanation:
 *
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void dfs(vector<vector<char>> &board, int r, int c) {
    int rows = board.size();
    int cols = board[0].size();

    board[r][c] = '$';

    for (auto dir : dirs) {
      int newR = r + dir.first;
      int newC = c + dir.second;

      if (newR >= 0 && newR < rows && newC >= 0 && newC < cols) {
        if (board[newR][newC] == 'O') {
          dfs(board, newR, newC);
        }
      }
    }
  }

public:
  void solve(vector<vector<char>> &board) {
    if (board.empty() || board[0].empty()) {
      return;
    }

    int rows = board.size();
    int cols = board[0].size();

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
          if (board[r][c] == 'O') {
            dfs(board, r, c);
          }
        }
      }
    }

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (board[r][c] == 'O') {
          board[r][c] = 'X';
        }

        if (board[r][c] == '$') {
          board[r][c] = 'O';
        }
      }
    }
  }
};
