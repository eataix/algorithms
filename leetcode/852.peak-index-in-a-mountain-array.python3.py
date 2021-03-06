#
# [882] Peak Index in a Mountain Array
#
# https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#
# algorithms
# Easy (77.40%)
# Total Accepted:    2.1K
# Total Submissions: 2.7K
# Testcase Example:  '[0,1,0]'
#
# Let's call an array A a mountain if the following properties hold:
#
#
# A.length >= 3
# There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] <
# A[i] > A[i+1] > ... > A[A.length - 1]
#
#
# Given an array that is definitely a mountain, return any i such that A[0] <
# A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
#
# Example 1:
#
#
# Input: [0,1,0]
# Output: 1
#
#
#
# Example 2:
#
#
# Input: [0,2,1,0]
# Output: 1
#
#
# Note:
#
#
# 3 <= A.length <= 10000
# 0 <= A[i] <= 10^6
# A is a mountain, as defined above.
#
#
#


class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        lower = 0
        upper = len(A) - 1
        while lower < upper:
            mid = lower + (upper - lower) // 2
            if A[mid] < A[mid + 1]:
                lower = mid + 1
            else:
                upper = mid
        return lower
