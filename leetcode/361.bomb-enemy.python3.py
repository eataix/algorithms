#
# [361] Bomb Enemy
#
# https://leetcode.com/problems/bomb-enemy/description/
#
# algorithms
# Medium (41.01%)
# Total Accepted:    26.7K
# Total Submissions: 65.1K
# Testcase Example:  '[["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]'
#
# Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0'
# (the number zero), return the maximum enemies you can kill using one bomb.
# The bomb kills all the enemies in the same row and column from the planted
# point until it hits the wall since the wall is too strong to be destroyed.
# Note: You can only put the bomb at an empty cell.
#
# Example:
#
#
#
# Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
# Output: 3
# Explanation: For the given grid,
#
# 0 E 0 0
# E 0 W E
# 0 E 0 0
#
# Placing a bomb at (1,1) kills 3 enemies.
#
#
#
#
class Solution:
    def maxKilledEnemies(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0

        numRows = len(grid)
        numCols = len(grid[0])

        colHits = [0] * numCols
        rowHits = 0
        res = 0
        from itertools import product
        for r, c in product(range(numRows), range(numCols)):
            if grid[r][c] != 'W':
                if c == 0 or grid[r][c - 1] == 'W':
                    rowHits = 0
                    k = c
                    while k < numCols and grid[r][k] != 'W':
                        rowHits += 1 if grid[r][k] == 'E' else 0
                        k += 1

                if r == 0 or grid[r - 1][c] == 'W':
                    colHits[c] = 0
                    k = r
                    while k < numRows and grid[k][c] != 'W':
                        colHits[c] += 1 if grid[k][c] == 'E' else 0
                        k += 1

                if grid[r][c] == '0':
                    res = max(res, rowHits + colHits[c])
        return res
