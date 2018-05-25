#include <utility>
#include <vector>
using namespace std;
/*
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (37.25%)
 * Total Accepted:    68.7K
 * Total Submissions: 184.4K
 * Testcase Example:  '[[]]'
 *
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 *
 *
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 *
 *
 *
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 *
 *
 *
 *
 * Write a function to compute the next state (after one update) of the board
 * given its current state.
 *
 *
 * Follow up:
 *
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 *
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
  vector<pair<int, int>> directions{{0, 1},  {0, -1}, {-1, -1}, {-1, 0},
                                    {-1, 1}, {1, -1}, {1, 0},   {1, 1}};

public:
  void gameOfLife(vector<vector<int>> &board) {
    if (board.empty() || board[0].empty()) {
      return;
    }

    int rows = board.size();
    int cols = board[0].size();

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        int count = 0;
        for (const auto &d : directions) {
          int newR = r + d.first;
          int newC = c + d.second;

          if (newR >= 0 && newR < rows && newC >= 0 && newC < cols &&
              (board[newR][newC] == 1 || board[newR][newC] == 2)) {
            count += 1;
          }
        }

        if (board[r][c] == 1) {
          if (count < 2 || count > 3) {
            board[r][c] = 2;
          }
        } else {
          if (count == 3) {
            board[r][c] = 3;
          }
        }
      }
    }
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        board[r][c] %= 2;
      }
    }
  }
};
