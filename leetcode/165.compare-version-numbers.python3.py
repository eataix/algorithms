#
# [165] Compare Version Numbers
#
# https://leetcode.com/problems/compare-version-numbers/description/
#
# algorithms
# Medium (21.26%)
# Total Accepted:    106.4K
# Total Submissions: 500.6K
# Testcase Example:  '"0.1"\n"1.1"'
#
# Compare two version numbers version1 and version2.
# If version1 > version2 return 1; if version1 < version2 return -1;otherwise
# return 0.
#
# You may assume that the version strings are non-empty and contain only digits
# and the . character.
# The . character does not represent a decimal point and is used to separate
# number sequences.
# For instance, 2.5 is not "two and a half" or "half way to version three", it
# is the fifth second-level revision of the second first-level revision.
#
# Example 1:
#
#
# Input: version1 = "0.1", version2 = "1.1"
# Output: -1
#
# Example 2:
#
#
# Input: version1 = "1.0.1", version2 = "1"
# Output: 1
#
# Example 3:
#
#
# Input: version1 = "7.5.2.4", version2 = "7.5.3"
# Output: -1
#
#
class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        ints1 = [int(v) for v in version1.split('.')]
        ints2 = [int(v) for v in version2.split('.')]

        for i in range(max(len(ints1), len(ints2))):
            if i < len(ints1):
                v1 = ints1[i]
            else:
                v1 = 0

            if i < len(ints2):
                v2 = ints2[i]
            else:
                v2 = 0

            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1

        return 0
