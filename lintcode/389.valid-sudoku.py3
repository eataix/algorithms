class Solution:
    """
    @param board: the board
    @return: whether the Sudoku is valid
    """
    def isValidSudoku(self, board):
        rows = [[False] * 9 for _ in range(9)]
        cols = [[False] * 9 for _ in range(9)]
        cells = [[False] * 9 for _ in range(9)]
        
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    continue
                v = ord(board[row][col]) - ord('1')
                cell = row // 3 * 3 + col // 3
                if rows[row][v] or cols[col][v] or cells[cell][v]:
                    return False
                rows[row][v] = True
                cols[col][v] = True
                cells[cell][v] = True

        return True
