#
# [73] Set Matrix Zeroes
#
# https://leetcode.com/problems/set-matrix-zeroes/description/
#
# algorithms
# Medium (36.75%)
# Total Accepted:    142.4K
# Total Submissions: 387.5K
# Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
#
# Given a m x n matrix, if an element is 0, set its entire row and column to 0.
# Do it in-place.
#
# Example 1:
#
#
# Input:
# [
# [1,1,1],
# [1,0,1],
# [1,1,1]
# ]
# Output:
# [
# [1,0,1],
# [0,0,0],
# [1,0,1]
# ]
#
#
# Example 2:
#
#
# Input:
# [
# [0,1,2,0],
# [3,4,5,2],
# [1,3,1,5]
# ]
# Output:
# [
# [0,0,0,0],
# [0,4,5,0],
# [0,3,1,0]
# ]
#
#
# Follow up:
#
#
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best
# solution.
# Could you devise a constant space solution?
#
#
#
class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return
        numRows = len(matrix)
        numCols = len(matrix[0])

        col0 = False

        from itertools import product

        for r in range(numRows):
            col0 = col0 or matrix[r][0] == 0

        for r, c in product(range(numRows), range(1, numCols)):
            if matrix[r][c] == 0:
                matrix[r][0] = 0
                matrix[0][c] = 0

        for r, c in product(
                reversed(range(numRows)), reversed(range(1, numCols))):
            if matrix[r][0] == 0 or matrix[0][c] == 0:
                matrix[r][c] = 0

        if col0:
            for r in range(numRows):
                matrix[r][0] = 0
