#
# [149] Max Points on a Line
#
# https://leetcode.com/problems/max-points-on-a-line/description/
#
# algorithms
# Hard (15.22%)
# Total Accepted:    99.7K
# Total Submissions: 654.7K
# Testcase Example:  '[[1,1],[2,2],[3,3]]'
#
# Given n points on a 2D plane, find the maximum number of points that lie on
# the same straight line.
#
# Example 1:
#
#
# Input: [[1,1],[2,2],[3,3]]
# Output: 3
# Explanation:
# ^
# |
# |        o
# |     o
# |  o
# +------------->
# 0  1  2  3  4
#
#
# Example 2:
#
#
# Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
# Output: 4
# Explanation:
# ^
# |
# |  o
# |     o        o
# |        o
# |  o        o
# +------------------->
# 0  1  2  3  4  5  6
#
#
#
# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b
# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b


class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """

        def gcd(a, b):
            if b == 0:
                return a
            return gcd(b, a % b)

        res = 0

        from collections import defaultdict
        for i, p1 in enumerate(points):
            m = defaultdict(int)
            duplicates = 1
            for p2 in points[i + 1:]:
                if p1.x == p2.x and p1.y == p2.y:
                    duplicates += 1
                    continue
                dx = p1.x - p2.x
                dy = p1.y - p2.y
                d = gcd(dx, dy)
                dx /= d
                dy /= d
                m[(dx, dy)] += 1

            res = max(res, duplicates)
            for _, v in m.items():
                res = max(res, v + duplicates)

        return res
