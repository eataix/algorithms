#
# [152] Maximum Product Subarray
#
# https://leetcode.com/problems/maximum-product-subarray/description/
#
# algorithms
# Medium (26.77%)
# Total Accepted:    137.9K
# Total Submissions: 515.2K
# Testcase Example:  '[2,3,-2,4]'
#
# Find the contiguous subarray within an array (containing at least one number)
# which has the largest product.
#
# For example, given the array [2,3,-2,4],
# the contiguous subarray [2,3] has the largest product = 6.
#
#
class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxV = nums[0]
        minV = nums[0]
        res = maxV

        for num in nums[1:]:
            if num < 0:
                maxV, minV = minV, maxV

            maxV = max(maxV * num, num)
            minV = min(minV * num, num)
            res = max(maxV, res)
        return res
