#
# [228] Summary Ranges
#
# https://leetcode.com/problems/summary-ranges/description/
#
# algorithms
# Medium (32.45%)
# Total Accepted:    100.8K
# Total Submissions: 310.5K
# Testcase Example:  '[0,1,2,4,5,7]'
#
# Given a sorted integer array without duplicates, return the summary of its
# ranges.
#
# Example 1:
#
#
# Input:  [0,1,2,4,5,7]
# Output: ["0->2","4->5","7"]
# Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
#
#
# Example 2:
#
#
# Input:  [0,2,3,4,6,8,9]
# Output: ["0","2->4","6","8->9"]
# Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
#
#
#
#
#
class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        n = len(nums)

        start = 0
        res = []
        while start < n:
            streak = 1

            while start + streak < n and nums[start + streak] == nums[start] + streak:
                streak += 1

            if streak == 1:
                res.append(str(nums[start]))
            else:
                res.append("{}->{}".format(nums[start], nums[start + streak - 1]))
            start += streak
        return res