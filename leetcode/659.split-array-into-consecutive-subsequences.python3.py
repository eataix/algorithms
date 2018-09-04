#
# [659] Split Array into Consecutive Subsequences
#
# https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
#
# algorithms
# Medium (37.40%)
# Total Accepted:    11.2K
# Total Submissions: 30K
# Testcase Example:  '[1,2,3,3,4,5]'
#
# You are given an integer array sorted in ascending order (may contain
# duplicates), you need to split them into several subsequences, where each
# subsequences consist of at least 3 consecutive integers. Return whether you
# can make such a split.
#
# Example 1:
#
# Input: [1,2,3,3,4,5]
# Output: True
# Explanation:
# You can split them into two consecutive subsequences :
# 1, 2, 3
# 3, 4, 5
#
#
#
# Example 2:
#
# Input: [1,2,3,3,4,4,5,5]
# Output: True
# Explanation:
# You can split them into two consecutive subsequences :
# 1, 2, 3, 4, 5
# 3, 4, 5
#
#
#
# Example 3:
#
# Input: [1,2,3,4,4,5]
# Output: False
#
#
#
# Note:
#
# The length of the input is in range of [1, 10000]
#
#
#
class Solution:
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        count = collections.Counter(nums)
        tails = collections.Counter()

        for num in nums:
            if count[num] == 0:
                continue
            elif tails[num] > 0:
                tails[num] -= 1
                tails[num + 1] += 1
            elif count[num + 1] > 0 and count[num + 2] > 0:
                count[num + 1] -= 1
                count[num + 2] -= 1
                tails[num + 3] += 1
            else:
                return False
            count[num] -= 1
        return True
