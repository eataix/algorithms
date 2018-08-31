#
# [209] Minimum Size Subarray Sum
#
# https://leetcode.com/problems/minimum-size-subarray-sum/description/
#
# algorithms
# Medium (32.96%)
# Total Accepted:    134.5K
# Total Submissions: 407.7K
# Testcase Example:  '7\n[2,3,1,2,4,3]'
#
# Given an array of n positive integers and a positive integer s, find the
# minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
# one, return 0 instead.
#
# Example:
#
#
# Input: s = 7, nums = [2,3,1,2,4,3]
# Output: 2
# Explanation: the subarray [4,3] has the minimal length under the problem
# constraint.
#
# Follow up:
#
# If you have figured out the O(n) solution, try coding another solution of
# which the time complexity is O(n log n).
#
#
class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """

        left = 0
        total = 0
        minLen = len(nums) + 1

        for right, num in enumerate(nums):
            total += num
            while total >= s:
                minLen = min(minLen, right - left + 1)
                total -= nums[left]
                left += 1

        return minLen if minLen <= len(nums) else 0
