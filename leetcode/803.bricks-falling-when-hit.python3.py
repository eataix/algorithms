#
# [821] Bricks Falling When Hit
#
# https://leetcode.com/problems/bricks-falling-when-hit/description/
#
# algorithms
# Hard (22.67%)
# Total Accepted:    2.5K
# Total Submissions: 10.9K
# Testcase Example:  '[[1,0,0,0],[1,1,1,0]]\n[[1,0]]'
#
# We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will
# not drop if and only if it is directly connected to the top of the grid, or
# at least one of its (4-way) adjacent bricks will not drop.
#
# We will do some erasures sequentially. Each time we want to do the erasure at
# the location (i, j), the brick (if it exists) on that location will
# disappear, and then some other bricks may drop because of that erasure.
#
# Return an array representing the number of bricks that will drop after each
# erasure in sequence.
#
#
# Example 1:
# Input:
# grid = [[1,0,0,0],[1,1,1,0]]
# hits = [[1,0]]
# Output: [2]
# Explanation:
# If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So
# we should return 2.
#
#
# Example 2:
# Input:
# grid = [[1,0,0,0],[1,1,0,0]]
# hits = [[1,1],[1,0]]
# Output: [0,0]
# Explanation:
# When we erase the brick at (1, 0), the brick at (1, 1) has already
# disappeared due to the last move. So each erasure will cause no bricks
# dropping.  Note that the erased brick (1, 0) will not be counted as a dropped
# brick.
#
#
#
# Note:
#
#
# The number of rows and columns in the grid will be in the range [1, 200].
# The number of erasures will not exceed the area of the grid.
# It is guaranteed that each erasure will be different from any other erasure,
# and located inside the grid.
# An erasure may refer to a location with no brick - if it does, no bricks
# drop.
#
#
#
from copy import deepcopy
class UnionFind:
    def __init__(self, n):
        self.parents = [i for i in range(n)]
        self.sizes = [1] * n
        self.ranks = [1] * n

    def find_set(self, i):
        if self.parents[i] != i:
            self.parents[i] = self.find_set(self.parents[i])
        return self.parents[i]

    def union_set(self, i, j):
        p = self.find_set(i)
        q = self.find_set(j)
        if p == q:
            return

        if self.ranks[p] < self.ranks[q]:
            p, q = q, p

        if p == q:
            self.ranks[p] += 1

        self.parents[q] = p
        self.sizes[p] += self.sizes[q]

    def size(self, i):
        return self.sizes[self.find_set(i)]

class Solution:
    def hitBricks(self, grid, hits):
        """
        :type grid: List[List[int]]
        :type hits: List[List[int]]
        :rtype: List[int]
        """
        A = deepcopy(grid)

        for hit in hits:
            r = hit[0]
            c = hit[1]
            A[r][c] = 0

        numRows = len(grid)
        numCols = len(grid[0])
        SB = numRows * numCols
        uf = UnionFind(SB + 1)

        def ID(r, c):
            return r * numCols + c

        for r in range(numRows):
            for c in range(numCols):
                if A[r][c] == 1:
                    if r == 0:
                        uf.union_set(SB, ID(r, c))
                    if r > 0 and A[r - 1][c] == 1:
                        uf.union_set(ID(r, c), ID(r - 1, c))
                    if c > 0 and A[r][c-1] == 1:
                        uf.union_set(ID(r, c), ID(r, c-1))
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        res = []
        for hit in hits[::-1]:
            r = hit[0]
            c = hit[1]
            if grid[r][c] == 1:
                pre = uf.size(SB)

                for dx, dy in directions:
                    nr = r + dx
                    nc = c + dy

                    if nr >= 0 and nr < numRows and nc >= 0 and nc < numCols and A[nr][nc] == 1:
                        uf.union_set(ID(nr, nc), ID(r, c))

                if r == 0:
                    uf.union_set(SB, ID(r, c))

                A[r][c] = 1
                after = uf.size(SB)

                res.append(max(0, after - pre -1))
            else:
                res.append(0)

        return res[::-1]
