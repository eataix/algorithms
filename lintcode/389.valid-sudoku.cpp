#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param board: the board
   * @return: whether the Sudoku is valid
   */
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> rows(9, vector<bool>(9, false));
    vector<vector<bool>> cols(9, vector<bool>(9, false));
    vector<vector<bool>> cells(9, vector<bool>(9, false));

    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] < '1' || board[r][c] > '9') {
          continue;
        }
        int v = board[r][c] - '1';

        if (rows[r][v]) {
          return false;
        }

        if (cols[c][v]) {
          return false;
        }

        int cell = r / 3 * 3 + c / 3;
        if (cells[cell][v]) {
          return false;
        }

        rows[r][v] = cols[c][v] = cells[cell][v] = true;
      }
    }

    return true;
  }
};
