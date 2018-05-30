#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param board: the sudoku puzzle
   * @return: nothing
   */
  void solveSudoku(vector<vector<int>> &board) { solveSudokuDFS(board, 0, 0); }

  bool solveSudokuDFS(vector<vector<int>> &board, int row, int col) {
    cout << row << " " << col << endl;
    if (row == 9) {
      cout << "solution" << endl;
      return true;
    } else if (col >= 9) {
      return solveSudokuDFS(board, row + 1, 0);
    } else {
      if (board[row][col] == 0) {
        for (int i = 1; i <= 9; ++i) {
          board[row][col] = i;

          if (isValid(board, row, col) && solveSudokuDFS(board, row, col + 1)) {
            return true;
          }
        }
        board[row][col] = 0;
      } else {
        return solveSudokuDFS(board, row, col + 1);
      }
    }
    return false;
  }

  bool isValid(const vector<vector<int>> &board, int r, int c) {
    for (int row = 0; row < 9; ++row) {
      if (row != r && board[row][c] == board[r][c]) {
        return false;
      }
    }

    for (int col = 0; col < 9; ++col) {
      if (col != c && board[r][col] == board[r][c]) {
        return false;
      }
    }

    for (int boxR = r / 3 * 3; boxR < (r / 3 + 1) * 3; ++boxR) {
      for (int boxC = c / 3 * 3; boxC < (c / 3 + 1) * 3; ++boxC) {
        if (boxR != r && boxC != c && board[boxR][boxC] == board[r][c])
          return false;
      }
    }

    return true;
  }
};

#ifdef DEBUG
int main() {
  vector<vector<int>> v{
      {0, 0, 9, 7, 4, 8, 0, 0, 0}, {7, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 2, 0, 1, 0, 9, 0, 0, 0}, {0, 0, 7, 0, 0, 0, 2, 4, 0},
      {0, 6, 4, 0, 1, 0, 5, 9, 0}, {0, 9, 8, 0, 0, 0, 3, 0, 0},
      {0, 0, 0, 8, 0, 3, 0, 2, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6},
      {0, 0, 0, 2, 7, 5, 9, 0, 0}};
  Solution sol;
  sol.solveSudoku(v);
}
#endif
