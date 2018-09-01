#
# [296] Best Meeting Point
#
# https://leetcode.com/problems/best-meeting-point/description/
#
# algorithms
# Hard (52.69%)
# Total Accepted:    18.3K
# Total Submissions: 34.8K
# Testcase Example:  '[[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]'
#
# A group of two or more people wants to meet and minimize the total travel
# distance. You are given a 2D grid of values 0 or 1, where each 1 marks the
# home of someone in the group. The distance is calculated using Manhattan
# Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
#
# Example:
#
#
# Input:
#
# 1 - 0 - 0 - 0 - 1
# |   |   |   |   |
# 0 - 0 - 0 - 0 - 0
# |   |   |   |   |
# 0 - 0 - 1 - 0 - 0
#
# Output: 6
#
# Explanation: Given three people living at (0,0), (0,4), and
# (2,2):
# The point (0,2) is an ideal meeting point, as the total travel
# distance
# of 2+2+2=6 is minimal. So return 6.
#
#
class Solution:
    def minTotalDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        def minDist(coords):
            coords.sort()
            left = 0
            right = len(coords) - 1
            res = 0
            while left < right:
                res += coords[right] - coords[left]
                left += 1
                right -= 1
            return res

        if len(grid) == 0 or len(grid[0]) == 0:
            return 0

        numRows = len(grid)
        numCols = len(grid[0])
        xs = list()
        ys = list()
        from itertools import product
        for r, c in product(range(numRows), range(numCols)):
            if grid[r][c] == 1:
                xs.append(r)
                ys.append(c)

        return minDist(xs) + minDist(ys)
