#
# [307] Range Sum Query - Mutable
#
# https://leetcode.com/problems/range-sum-query-mutable/description/
#
# algorithms
# Medium (24.10%)
# Total Accepted:    51K
# Total Submissions: 210.9K
# Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
#
# Given an integer array nums, find the sum of the elements between indices i
# and j (i ≤ j), inclusive.
#
# The update(i, val) function modifies nums by updating the element at index i
# to val.
#
# Example:
#
#
# Given nums = [1, 3, 5]
#
# sumRange(0, 2) -> 9
# update(1, 2)
# sumRange(0, 2) -> 8
#
#
# Note:
#
#
# The array is only modifiable by the update function.
# You may assume the number of calls to update and sumRange function is
# distributed evenly.
#
#
#


def low_bit(i):
    return i & -i


class BIT:
    def __init__(self, n):
        self.nums = [0] * (n + 1)

    def add(self, i, val):
        i += 1
        while i < len(self.nums):
            self.nums[i] += val
            i += low_bit(i)

    def query(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.nums[i]
            i -= low_bit(i)
        return res


class NumArray:
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = [0] * len(nums)
        self.bit = BIT(len(nums))

        for idx, elem in enumerate(nums):
            self.update(idx, elem)

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        delta = val - self.nums[i]
        self.nums[i] = val
        self.bit.add(i, delta)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.bit.query(j) - self.bit.query(i - 1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
